--- supercop-20200826/crypto_decode/761x4591/avx/decode.c	2020-08-31 09:55:07.065788290 -0400
+++ supercop-20200826-patched/crypto_decode/761x4591/avx/decode.c	2020-08-31 07:48:47.710953136 -0400
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
     a0 = mulhi(a0,-545)-mulhi(mullo(a0,-1661),10101); /* -5187...5050 */
     a0 += s[2*i+1]; /* -5187...5305 */
     a0 = mulhi(a0,-545)-mulhi(mullo(a0,-1661),10101); /* -5095...5093 */
@@ -217,7 +217,7 @@
   R5[23] = a1;
   s -= 22;
   for (i = 10;i >= 0;--i) {
-    a2 = a0 = R6[i];
+    a0 = R6[i];
     a0 = mulhi(a0,4206)-mulhi(mullo(a0,-1634),10265); /* -5133...6184 */
     a0 += s[2*i+1]; /* -5133...6439 */
     a0 = mulhi(a0,4206)-mulhi(mullo(a0,-1634),10265); /* -5462...5545 */
@@ -238,7 +238,7 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R5[23];
+  a0 = R5[23];
   a0 = mulhi(a0,-134)-mulhi(mullo(a0,-10350),1621); /* -844...810 */
   a0 += s[2*i+1]; /* -844...1065 */
   a0 = mulhi(a0,-134)-mulhi(mullo(a0,-10350),1621); /* -813...812 */
@@ -406,7 +406,7 @@
   s -= 760;
   i = 364;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/857x1723/avx/decode.c supercop-20200826-patched/crypto_decode/857x1723/avx/decode.c
