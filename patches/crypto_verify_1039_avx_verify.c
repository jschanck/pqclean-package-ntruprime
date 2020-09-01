--- supercop-20200826/crypto_verify/1039/avx/verify.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_verify/1039/avx/verify.c	2020-09-01 15:35:26.050447734 -0400
@@ -26,10 +26,10 @@
   diff |= _mm256_srli_epi32(diff,16);
   diff |= _mm256_srli_epi64(diff,32);
 
-  differentbits = _mm256_extract_epi8(diff,0);
-  differentbits |= _mm256_extract_epi8(diff,8);
-  differentbits |= _mm256_extract_epi8(diff,16);
-  differentbits |= _mm256_extract_epi8(diff,24);
+  differentbits = (unsigned int) _mm256_extract_epi8(diff,0);
+  differentbits |= (unsigned int) _mm256_extract_epi8(diff,8);
+  differentbits |= (unsigned int) _mm256_extract_epi8(diff,16);
+  differentbits |= (unsigned int) _mm256_extract_epi8(diff,24);
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
diff -ru --no-dereference supercop-20200826/crypto_verify/1039/ref/verify.c supercop-20200826-patched/crypto_verify/1039/ref/verify.c
