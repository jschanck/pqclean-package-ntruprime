--- supercop-20200826/crypto_decode/653x4621/avx/decode.c	2020-08-31 09:55:07.061788342 -0400
+++ supercop-20200826-patched/crypto_decode/653x4621/avx/decode.c	2020-08-31 07:48:47.706955701 -0400
@@ -60,7 +60,7 @@
 static inline __m256i ifgesubconst(__m256i x,int16 y)
 {
   __m256i y16 = _mm256_set1_epi16(y);
-  __m256i top16 = _mm256_set1_epi16(y-1);
+  __m256i top16 = _mm256_set1_epi16((int16)(y-1));
   return sub(x,_mm256_cmpgt_epi16(x,top16) & y16);
 }
 
@@ -90,7 +90,7 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R10[0];
+  a0 = R10[0];
   a0 = mulhi(a0,396)-mulhi(mullo(a0,-20092),835); /* -418...516 */
   a0 += s[2*i+1]; /* -418...771 */
   a0 = mulhi(a0,396)-mulhi(mullo(a0,-20092),835); /* -421...422 */
@@ -131,7 +131,6 @@
   
   /* R8 ------> R7: reconstruct mod 5*[86]+[78] */
   
-  i = 0;
   s -= 0;
   a2 = a0 = R8[2];
   a0 = mulhi(a0,4)-mulhi(mullo(a0,-762),86); /* -43...44 */
@@ -188,7 +187,7 @@
   R5[20] = R6[10];
   s -= 20;
   for (i = 9;i >= 0;--i) {
-    a2 = a0 = R6[i];
+    a0 = R6[i];
     a0 = mulhi(a0,4710)-mulhi(mullo(a0,-1346),12461); /* -6231...7408 */
     a0 += s[2*i+1]; /* -6231...7663 */
     a0 = mulhi(a0,4710)-mulhi(mullo(a0,-1346),12461); /* -6679...6781 */
@@ -379,7 +378,7 @@
   s -= 652;
   i = 310;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/761x1531/avx/decode.c supercop-20200826-patched/crypto_decode/761x1531/avx/decode.c
