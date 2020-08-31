--- supercop-20200826/crypto_verify/1039/avx/verify.c	2020-08-31 09:55:07.117787624 -0400
+++ supercop-20200826-patched/crypto_verify/1039/avx/verify.c	2020-08-31 07:48:47.778909537 -0400
@@ -31,5 +31,5 @@
   differentbits |= _mm256_extract_epi8(diff,16);
   differentbits |= _mm256_extract_epi8(diff,24);
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
diff -ru --no-dereference supercop-20200826/crypto_verify/1039/ref/verify.c supercop-20200826-patched/crypto_verify/1039/ref/verify.c
