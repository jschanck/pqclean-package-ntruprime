--- supercop-20200826/crypto_verify/1025/avx/verify.c	2020-08-31 09:55:07.113787676 -0400
+++ supercop-20200826-patched/crypto_verify/1025/avx/verify.c	2020-08-31 07:48:47.774912101 -0400
@@ -31,5 +31,5 @@
   differentbits |= _mm256_extract_epi8(diff,16);
   differentbits |= _mm256_extract_epi8(diff,24);
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
diff -ru --no-dereference supercop-20200826/crypto_verify/1025/ref/verify.c supercop-20200826-patched/crypto_verify/1025/ref/verify.c
