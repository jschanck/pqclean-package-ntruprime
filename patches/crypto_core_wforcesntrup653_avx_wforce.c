--- supercop-20200826/crypto_core/wforcesntrup653/avx/wforce.c	2020-08-31 09:55:07.053788444 -0400
+++ supercop-20200826-patched/crypto_core/wforcesntrup653/avx/wforce.c	2020-08-31 07:48:47.698960830 -0400
@@ -21,7 +21,7 @@
 
   mask = (weight-w)|(w-weight);
   mask >>= 15;
-  maskvec = _mm256_set1_epi16(~mask);
+  maskvec = _mm256_set1_epi16((short) ~mask);
 
   i = w-32;
   for (;;) {
diff -ru --no-dereference supercop-20200826/crypto_core/wforcesntrup761/avx/wforce.c supercop-20200826-patched/crypto_core/wforcesntrup761/avx/wforce.c
