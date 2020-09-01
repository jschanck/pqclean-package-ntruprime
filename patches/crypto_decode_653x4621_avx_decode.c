--- supercop-20200826/crypto_decode/653x4621/avx/decode.c	2020-08-31 20:12:38.905042235 -0400
+++ supercop-20200826-patched/crypto_decode/653x4621/avx/decode.c	2020-08-31 20:16:25.470355358 -0400
@@ -14,7 +14,7 @@
 
 static inline int16 mulhi(int16 x,int16 y)
 {
-  return (x*(int32)y)>>16;
+  return (int16) ((x*(int32)y)>>16);
 }
 
 static inline __m256i add(__m256i x,__m256i y)
@@ -60,7 +60,7 @@
 static inline __m256i ifgesubconst(__m256i x,int16 y)
 {
   __m256i y16 = _mm256_set1_epi16(y);
-  __m256i top16 = _mm256_set1_epi16(y-1);
+  __m256i top16 = _mm256_set1_epi16((int16)(y-1));
   return sub(x,_mm256_cmpgt_epi16(x,top16) & y16);
 }
 
@@ -90,13 +90,13 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R10[0];
+  a0 = R10[0];
   a0 = mulhi(a0,396)-mulhi(mullo(a0,-20092),835); /* -418...516 */
   a0 += s[2*i+1]; /* -418...771 */
   a0 = mulhi(a0,396)-mulhi(mullo(a0,-20092),835); /* -421...422 */
   a0 += s[2*i+0]; /* -421...677 */
   a0 += (a0>>15)&835; /* 0...834 */
-  a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+  a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
   a1 = mullo(a1,8555);
 
   /* invalid inputs might need reduction mod 6708 */
@@ -118,7 +118,7 @@
     a0 = mulhi(a0,3088)-mulhi(mullo(a0,-2268),7396); /* -3873...3920 */
     a0 += s[2*i+0]; /* -3873...4175 */
     a0 += (a0>>15)&7396; /* 0...7395 */
-    a1 = (a2<<14)+(s[2*i+1]<<6)+((s[2*i]-a0)>>2);
+    a1 = (int16) ((a2<<14)+(s[2*i+1]<<6)+((s[2*i]-a0)>>2));
     a1 = mullo(a1,-18679);
 
     /* invalid inputs might need reduction mod 7396 */
@@ -131,12 +131,11 @@
   
   /* R8 ------> R7: reconstruct mod 5*[86]+[78] */
   
-  i = 0;
   s -= 0;
   a2 = a0 = R8[2];
   a0 = mulhi(a0,4)-mulhi(mullo(a0,-762),86); /* -43...44 */
   a0 += (a0>>15)&86; /* 0...85 */
-  a1 = (a2-a0)>>1;
+  a1 = (int16) ((a2-a0)>>1);
   a1 = mullo(a1,-16765);
 
   /* invalid inputs might need reduction mod 78 */
@@ -150,7 +149,7 @@
     a2 = a0 = R8[i];
     a0 = mulhi(a0,4)-mulhi(mullo(a0,-762),86); /* -43...44 */
     a0 += (a0>>15)&86; /* 0...85 */
-    a1 = (a2-a0)>>1;
+    a1 = (int16) ((a2-a0)>>1);
     a1 = mullo(a1,-16765);
 
     /* invalid inputs might need reduction mod 86 */
@@ -172,7 +171,7 @@
     a0 = mulhi(a0,-14)-mulhi(mullo(a0,-7079),2370); /* -1186...1185 */
     a0 += s[2*i+0]; /* -1186...1440 */
     a0 += (a0>>15)&2370; /* 0...2369 */
-    a1 = (a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1);
+    a1 = (int16) ((a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1));
     a1 = mullo(a1,-8351);
 
     /* invalid inputs might need reduction mod 2370 */
@@ -188,13 +187,13 @@
   R5[20] = R6[10];
   s -= 20;
   for (i = 9;i >= 0;--i) {
-    a2 = a0 = R6[i];
+    a0 = R6[i];
     a0 = mulhi(a0,4710)-mulhi(mullo(a0,-1346),12461); /* -6231...7408 */
     a0 += s[2*i+1]; /* -6231...7663 */
     a0 = mulhi(a0,4710)-mulhi(mullo(a0,-1346),12461); /* -6679...6781 */
     a0 += s[2*i+0]; /* -6679...7036 */
     a0 += (a0>>15)&12461; /* 0...12460 */
-    a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+    a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
     a1 = mullo(a1,-19675);
 
     /* invalid inputs might need reduction mod 12461 */
@@ -248,7 +247,7 @@
   a0 = mulhi(a0,248)-mulhi(mullo(a0,-24818),676); /* -340...340 */
   a0 += s[2*i+0]; /* -340...595 */
   a0 += (a0>>15)&676; /* 0...675 */
-  a1 = (a2<<14)+(s[2*i+1]<<6)+((s[2*i]-a0)>>2);
+  a1 = (int16) ((a2<<14)+(s[2*i+1]<<6)+((s[2*i]-a0)>>2));
   a1 = mullo(a1,-23655);
 
   /* invalid inputs might need reduction mod 7510 */
@@ -297,7 +296,7 @@
   a0 -= 416; /* -640..>47 */
   a0 += (a0>>15)&416; /* -224...415 */
   a0 += (a0>>15)&416; /* 0...415 */
-  a1 = (a2<<3)+((s[i]-a0)>>5);
+  a1 = (int16) ((a2<<3)+((s[i]-a0)>>5));
   a1 = mullo(a1,20165);
 
   /* invalid inputs might need reduction mod 4621 */
@@ -379,7 +378,7 @@
   s -= 652;
   i = 310;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/653x4621/int16/decode.c supercop-20200826-patched/crypto_decode/653x4621/int16/decode.c
