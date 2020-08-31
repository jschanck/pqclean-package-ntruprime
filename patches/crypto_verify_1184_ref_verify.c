--- supercop-20200826/crypto_verify/1184/ref/verify.c	2020-08-31 09:55:07.125787522 -0400
+++ supercop-20200826-patched/crypto_verify/1184/ref/verify.c	2020-08-31 07:48:47.786904408 -0400
@@ -8,5 +8,5 @@
   for (i = 0;i < crypto_verify_BYTES;++i)
     differentbits |= x[i] ^ y[i];
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
diff -ru --no-dereference supercop-20200826/crypto_verify/1312/avx/verify.c supercop-20200826-patched/crypto_verify/1312/avx/verify.c
