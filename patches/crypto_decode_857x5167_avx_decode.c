--- supercop-20200826/crypto_decode/857x5167/avx/decode.c	2020-08-28 13:06:30.993178969 -0400
+++ supercop-20200826-patched/crypto_decode/857x5167/avx/decode.c	2020-08-28 12:38:23.457144777 -0400
@@ -60,7 +60,7 @@
 static inline __m256i ifgesubconst(__m256i x,int16 y)
 {
   __m256i y16 = _mm256_set1_epi16(y);
-  __m256i top16 = _mm256_set1_epi16(y-1);
+  __m256i top16 = _mm256_set1_epi16((int16)(y-1));
   return sub(x,_mm256_cmpgt_epi16(x,top16) & y16);
 }
 
@@ -164,7 +164,7 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R7[6];
+  a0 = R7[6];
   a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -5996...6447 */
   a0 += s[2*i+1]; /* -5996...6702 */
   a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -6161...6180 */
@@ -181,7 +181,7 @@
   R6[13] = a1;
   s -= 12;
   for (i = 5;i >= 0;--i) {
-    a2 = a0 = R7[i];
+    a0 = R7[i];
     a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -5996...6447 */
     a0 += s[2*i+1]; /* -5996...6702 */
     a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -6161...6180 */
@@ -238,7 +238,7 @@
   s -= 52;
   i = 10;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -394,7 +394,7 @@
   s -= 856;
   i = 412;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_encode/256x2/avx/encode.c supercop-20200826-patched/crypto_encode/256x2/avx/encode.c
