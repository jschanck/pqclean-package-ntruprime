--- supercop-20200826/crypto_verify/1184/avx/verify.c	2020-08-28 13:06:31.021178965 -0400
+++ supercop-20200826-patched/crypto_verify/1184/avx/verify.c	2020-08-28 12:38:23.501144802 -0400
@@ -31,5 +31,5 @@
   differentbits |= _mm256_extract_epi8(diff,16);
   differentbits |= _mm256_extract_epi8(diff,24);
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
diff -ru --no-dereference supercop-20200826/crypto_verify/1184/ref/verify.c supercop-20200826-patched/crypto_verify/1184/ref/verify.c
