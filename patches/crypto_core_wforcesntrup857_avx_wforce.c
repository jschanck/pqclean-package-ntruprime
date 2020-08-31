--- supercop-20200826/crypto_core/wforcesntrup857/avx/wforce.c	2020-08-31 09:55:07.057788393 -0400
+++ supercop-20200826-patched/crypto_core/wforcesntrup857/avx/wforce.c	2020-08-31 07:48:47.702958266 -0400
@@ -21,7 +21,7 @@
 
   mask = (weight-w)|(w-weight);
   mask >>= 15;
-  maskvec = _mm256_set1_epi16(~mask);
+  maskvec = _mm256_set1_epi16((short) ~mask);
 
   i = w-32;
   for (;;) {
diff -ru --no-dereference supercop-20200826/crypto_decode/653x1541/avx/decode.c supercop-20200826-patched/crypto_decode/653x1541/avx/decode.c
