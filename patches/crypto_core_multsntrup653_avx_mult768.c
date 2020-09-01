--- supercop-20200826/crypto_core/multsntrup653/avx/mult768.c	2020-08-31 20:12:38.865041988 -0400
+++ supercop-20200826-patched/crypto_core/multsntrup653/avx/mult768.c	2020-08-31 20:09:19.723726578 -0400
@@ -15,6 +15,21 @@
 #define mulhrs_x16 _mm256_mulhrs_epi16
 #define signmask_x16(x) _mm256_srai_epi16((x),15)
 
+typedef union {
+  int16 v[3][512];
+  int16x16 _dummy;
+} vec3x512;
+
+typedef union {
+  int16 v[768];
+  int16x16 _dummy;
+} vec768;
+
+typedef union {
+  int16 v[3*512];
+  int16x16 _dummy;
+} vec1536;
+
 static inline int16x16 squeeze_4621_x16(int16x16 x)
 {
   return sub_x16(x,mullo_x16(mulhrs_x16(x,const_x16(7)),const_x16(4621)));
@@ -156,15 +171,15 @@
   }
 }
 
-#define ALIGNED __attribute((aligned(32)))
-
 static void mult768(int16 h[1536],const int16 f[768],const int16 g[768])
 {
-  ALIGNED int16 fpad[3][512];
-  ALIGNED int16 gpad[3][512];
+  vec3x512 x1, x2;
+  vec1536 x3, x4;
+#define fpad (x1.v)
+#define gpad (x2.v)
 #define hpad fpad
-  ALIGNED int16 h_7681[1536];
-  ALIGNED int16 h_10753[1536];
+#define h_7681 (x3.v)
+#define h_10753 (x4.v)
   int i;
 
   good(fpad,f);
@@ -193,7 +208,7 @@
   }
 
   invntt512_7681(hpad[0],3);
-  ungood(h_7681,hpad);
+  ungood(h_7681,(const int16(*)[512]) hpad);
 
   good(fpad,f);
   ntt512_10753(fpad[0],3);
@@ -221,7 +236,7 @@
   }
 
   invntt512_10753(hpad[0],3);
-  ungood(h_10753,hpad);
+  ungood(h_10753,(const int16(*)[512]) hpad);
 
   for (i = 0;i < 1536;i += 16) {
     int16x16 u1 = load_x16(&h_10753[i]);
@@ -256,9 +271,11 @@
 
 int crypto_core(unsigned char *outbytes,const unsigned char *inbytes,const unsigned char *kbytes,const unsigned char *cbytes)
 {
-  ALIGNED int16 f[768];
-  ALIGNED int16 g[768];
-  ALIGNED int16 fg[1536];
+  vec768 x1, x2;
+  vec1536 x3;
+#define f (x1.v)
+#define g (x2.v)
+#define fg (x3.v)
 #define h f
   int i;
   int16x16 x;
@@ -275,9 +292,9 @@
     store_x16(&f[i],x);
   }
   for (i = 0;i < p;++i) {
-    int8 gi = kbytes[i];
+    int8 gi = (int8) kbytes[i];
     int8 gi0 = gi&1;
-    g[i] = gi0-(gi&(gi0<<1));
+    g[i] = (int16) (gi0-(gi&((int16) gi0<<1)));
   }
 
   mult768(fg,f,g);
diff -ru --no-dereference supercop-20200826/crypto_core/multsntrup653/avx/ntt.c supercop-20200826-patched/crypto_core/multsntrup653/avx/ntt.c
