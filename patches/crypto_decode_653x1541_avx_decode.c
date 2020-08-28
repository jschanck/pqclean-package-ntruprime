--- supercop-20200826/crypto_decode/653x1541/avx/decode.c	2020-08-28 13:06:30.985178971 -0400
+++ supercop-20200826-patched/crypto_decode/653x1541/avx/decode.c	2020-08-28 12:38:23.453144775 -0400
@@ -60,7 +60,7 @@
 static inline __m256i ifgesubconst(__m256i x,int16 y)
 {
   __m256i y16 = _mm256_set1_epi16(y);
-  __m256i top16 = _mm256_set1_epi16(y-1);
+  __m256i top16 = _mm256_set1_epi16((int16)(y-1));
   return sub(x,_mm256_cmpgt_epi16(x,top16) & y16);
 }
 
@@ -145,7 +145,7 @@
   R7[5] = a1;
   s -= 4;
   for (i = 1;i >= 0;--i) {
-    a2 = a0 = R8[i];
+    a0 = R8[i];
     a0 = mulhi(a0,1223)-mulhi(mullo(a0,-5681),2953); /* -1477...1782 */
     a0 += s[2*i+1]; /* -1477...2037 */
     a0 = mulhi(a0,1223)-mulhi(mullo(a0,-5681),2953); /* -1505...1514 */
@@ -241,7 +241,7 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R4[40];
+  a0 = R4[40];
   a0 = mulhi(a0,2401)-mulhi(mullo(a0,-2487),6745); /* -3373...3972 */
   a0 += s[2*i+1]; /* -3373...4227 */
   a0 = mulhi(a0,2401)-mulhi(mullo(a0,-2487),6745); /* -3497...3527 */
@@ -259,7 +259,7 @@
   s -= 80;
   i = 24;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R4[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R4[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -343,7 +343,7 @@
   s -= 326;
   i = 147;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/653x4621/avx/decode.c supercop-20200826-patched/crypto_decode/653x4621/avx/decode.c
