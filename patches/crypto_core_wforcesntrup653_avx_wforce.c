--- supercop-20200826/crypto_core/wforcesntrup653/avx/wforce.c	2020-08-31 19:56:55.539747414 -0400
+++ supercop-20200826-patched/crypto_core/wforcesntrup653/avx/wforce.c	2020-08-31 20:09:19.747726749 -0400
@@ -19,9 +19,9 @@
   crypto_core_weight((unsigned char *) &weight,in,0,0);
   crypto_decode_int16(&weight,(unsigned char *) &weight);
 
-  mask = (weight-w)|(w-weight);
+  mask = (int16) ((weight-w)|(w-weight));
   mask >>= 15;
-  maskvec = _mm256_set1_epi16(~mask);
+  maskvec = _mm256_set1_epi16((short) ~mask);
 
   i = w-32;
   for (;;) {
diff -ru --no-dereference supercop-20200826/crypto_core/wforcesntrup653/ref/wforce.c supercop-20200826-patched/crypto_core/wforcesntrup653/ref/wforce.c
