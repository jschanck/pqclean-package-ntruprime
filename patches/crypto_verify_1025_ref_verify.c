--- supercop-20200826/crypto_verify/1025/ref/verify.c
+++ supercop-20200826-patched/crypto_verify/1025/ref/verify.c
@@ -8,5 +8,5 @@
   for (i = 0;i < crypto_verify_BYTES;++i)
     differentbits |= x[i] ^ y[i];
 
-  return (1 & ((differentbits - 1) >> 8)) - 1;
+  return (int) (1 & ((differentbits - 1) >> 8)) - 1;
 }

