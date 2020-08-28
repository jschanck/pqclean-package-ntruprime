--- supercop-20200826/crypto_verify/1167/ref/verify.c	2020-08-28 13:06:31.021178965 -0400
+++ supercop-20200826-patched/crypto_verify/1167/ref/verify.c	2020-08-28 12:38:23.497144800 -0400
@@ -8,5 +8,5 @@
   for (i = 0;i < crypto_verify_BYTES;++i)
     differentbits |= x[i] ^ y[i];
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
diff -ru --no-dereference supercop-20200826/crypto_verify/1184/avx/verify.c supercop-20200826-patched/crypto_verify/1184/avx/verify.c
