--- supercop-20200826/crypto_core/mult3sntrup653/ref/mult.c	2020-08-25 20:26:59.000000000 -0400
+++ supercop-20200826-patched/crypto_core/mult3sntrup653/ref/mult.c	2020-09-01 15:35:25.918448224 -0400
@@ -10,7 +10,7 @@
 /* works for -16384 <= x < 16384 */
 static small F3_freeze(int16 x)
 {
-  return x-3*((10923*x+16384)>>15);
+  return (small) (x-3*((10923*x+16384)>>15));
 }
 
 int crypto_core(unsigned char *outbytes,const unsigned char *inbytes,const unsigned char *kbytes,const unsigned char *cbytes)
@@ -23,24 +23,24 @@
   int i,j;
 
   for (i = 0;i < p;++i) {
-    small fi = inbytes[i];
+    small fi = (small) inbytes[i];
     small fi0 = fi&1;
-    f[i] = fi0-(fi&(fi0<<1));
+    f[i] = (small) (fi0-(fi&(fi0<<1)));
   }
   for (i = 0;i < p;++i) {
-    small gi = kbytes[i];
+    small gi = (small) kbytes[i];
     small gi0 = gi&1;
-    g[i] = gi0-(gi&(gi0<<1));
+    g[i] = (small) (gi0-(gi&(gi0<<1)));
   }
 
   for (i = 0;i < p;++i) {
     result = 0;
-    for (j = 0;j <= i;++j) result += f[j]*g[i-j];
+    for (j = 0;j <= i;++j) result += (small) (f[j]*g[i-j]);
     fg[i] = F3_freeze(result);
   }
   for (i = p;i < p+p-1;++i) {
     result = 0;
-    for (j = i-p+1;j < p;++j) result += f[j]*g[i-j];
+    for (j = i-p+1;j < p;++j) result += (small) (f[j]*g[i-j]);
     fg[i] = F3_freeze(result);
   }
 
diff -ru --no-dereference supercop-20200826/crypto_core/mult3sntrup761/avx/mult768.c supercop-20200826-patched/crypto_core/mult3sntrup761/avx/mult768.c
