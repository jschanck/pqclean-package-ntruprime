--- supercop-20200826/crypto_verify/897/ref/verify.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_verify/897/ref/verify.c	2020-09-01 15:35:26.066447675 -0400
@@ -8,5 +8,5 @@
   for (i = 0;i < crypto_verify_BYTES;++i)
     differentbits |= x[i] ^ y[i];
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }
