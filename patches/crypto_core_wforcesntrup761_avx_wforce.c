--- supercop-20200826/crypto_core/wforcesntrup761/avx/wforce.c	2020-08-28 13:06:30.985178971 -0400
+++ supercop-20200826-patched/crypto_core/wforcesntrup761/avx/wforce.c	2020-08-28 12:38:23.449144772 -0400
@@ -21,7 +21,7 @@
 
   mask = (weight-w)|(w-weight);
   mask >>= 15;
-  maskvec = _mm256_set1_epi16(~mask);
+  maskvec = _mm256_set1_epi16((short) ~mask);
 
   i = w-32;
   for (;;) {
diff -ru --no-dereference supercop-20200826/crypto_core/wforcesntrup857/avx/wforce.c supercop-20200826-patched/crypto_core/wforcesntrup857/avx/wforce.c
