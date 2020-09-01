--- supercop-20200826/crypto_core/weightsntrup761/avx/weight.c	2020-08-31 20:12:38.885042111 -0400
+++ supercop-20200826-patched/crypto_core/weightsntrup761/avx/weight.c	2020-08-31 20:09:19.743726720 -0400
@@ -18,8 +18,7 @@
   int16 weight;
 
   sum = _mm256_loadu_si256((__m256i *) (in+p-32));
-  sum &= endingmask;
-
+  sum &= _mm256_set_epi8(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0);
   for (i = p-32;i >= 0;i -= 32) {
     __m256i bits = _mm256_loadu_si256((__m256i *) in);
     bits &= _mm256_set1_epi8(1);
@@ -40,8 +39,8 @@
   sum = _mm256_hadd_epi16(sum,sum);
   /* want sum[0]+sum[8] */
 
-  weight = _mm256_extract_epi16(sum,0);
-  weight += _mm256_extract_epi16(sum,8);
+  weight = (int16) _mm256_extract_epi16(sum,0);
+  weight += (int16) _mm256_extract_epi16(sum,8);
 
   crypto_encode_int16(outbytes,&weight);
   return 0;
diff -ru --no-dereference supercop-20200826/crypto_core/weightsntrup857/avx/weight.c supercop-20200826-patched/crypto_core/weightsntrup857/avx/weight.c
