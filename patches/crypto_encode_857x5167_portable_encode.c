--- supercop-20200826/crypto_encode/857x5167/portable/encode.c	2020-08-31 09:55:07.105787778 -0400
+++ supercop-20200826-patched/crypto_encode/857x5167/portable/encode.c	2020-08-31 07:48:47.766917231 -0400
@@ -119,5 +119,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/857xfreeze3/ref/encode.c
