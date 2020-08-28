--- supercop-20200826/crypto_core/weightsntrup857/avx/weight.c	2020-08-28 13:06:30.981178972 -0400
+++ supercop-20200826-patched/crypto_core/weightsntrup857/avx/weight.c	2020-08-28 13:10:45.693132850 -0400
@@ -18,7 +18,7 @@
   int16 weight;
 
   sum = _mm256_loadu_si256((__m256i *) (in+p-32));
-  sum &= endingmask;
+  sum &= _mm256_set_epi8(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0);
 
   for (i = p-32;i >= 0;i -= 32) {
     __m256i bits = _mm256_loadu_si256((__m256i *) in);
diff -ru --no-dereference supercop-20200826/crypto_core/wforcesntrup653/avx/wforce.c supercop-20200826-patched/crypto_core/wforcesntrup653/avx/wforce.c
