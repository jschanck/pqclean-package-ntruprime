--- supercop-20200826/crypto_decode/857x1723/avx/decode.c	2020-08-31 09:55:07.065788290 -0400
+++ supercop-20200826-patched/crypto_decode/857x1723/avx/decode.c	2020-08-31 07:48:47.714950572 -0400
@@ -60,7 +60,7 @@
 static inline __m256i ifgesubconst(__m256i x,int16 y)
 {
   __m256i y16 = _mm256_set1_epi16(y);
-  __m256i top16 = _mm256_set1_epi16(y-1);
+  __m256i top16 = _mm256_set1_epi16((int16)(y-1));
   return sub(x,_mm256_cmpgt_epi16(x,top16) & y16);
 }
 
@@ -88,7 +88,7 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R10[0];
+  a0 = R10[0];
   a0 = mulhi(a0,276)-mulhi(mullo(a0,-22580),743); /* -372...440 */
   a0 += s[2*i+1]; /* -372...695 */
   a0 = mulhi(a0,276)-mulhi(mullo(a0,-22580),743); /* -374...374 */
@@ -245,7 +245,7 @@
   s -= 52;
   i = 10;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -328,7 +328,7 @@
   s -= 214;
   i = 91;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R3[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R3[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -365,7 +365,7 @@
   s -= 428;
   i = 198;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/857x5167/avx/decode.c supercop-20200826-patched/crypto_decode/857x5167/avx/decode.c
