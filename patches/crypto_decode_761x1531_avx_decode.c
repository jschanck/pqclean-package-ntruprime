--- supercop-20200826/crypto_decode/761x1531/avx/decode.c	2020-08-28 13:06:30.989178970 -0400
+++ supercop-20200826-patched/crypto_decode/761x1531/avx/decode.c	2020-08-28 12:38:23.457144777 -0400
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
-  a2 = a0 = R7[5];
+  a0 = R7[5];
   a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4549...5135 */
   a0 += s[2*i+1]; /* -4549...5390 */
   a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4712...4741 */
@@ -181,7 +181,7 @@
   R6[11] = a1;
   s -= 10;
   for (i = 4;i >= 0;--i) {
-    a2 = a0 = R7[i];
+    a0 = R7[i];
     a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4549...5135 */
     a0 += s[2*i+1]; /* -4549...5390 */
     a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4712...4741 */
@@ -371,7 +371,7 @@
   s -= 380;
   i = 174;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/761x4591/avx/decode.c supercop-20200826-patched/crypto_decode/761x4591/avx/decode.c
