--- supercop-20200826/crypto_verify/1312/ref/verify.c	2020-08-31 19:56:55.619748738 -0400
+++ supercop-20200826-patched/crypto_verify/1312/ref/verify.c	2020-08-31 20:09:19.835727374 -0400
@@ -8,5 +8,5 @@
   for (i = 0;i < crypto_verify_BYTES;++i)
     differentbits |= x[i] ^ y[i];
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
diff -ru --no-dereference supercop-20200826/crypto_verify/897/avx/verify.c supercop-20200826-patched/crypto_verify/897/avx/verify.c
