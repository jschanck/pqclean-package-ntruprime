--- supercop-20200826/crypto_encode/857x5167/portable/encode.c	2020-08-28 13:06:31.013178966 -0400
+++ supercop-20200826-patched/crypto_encode/857x5167/portable/encode.c	2020-08-28 12:38:23.489144796 -0400
@@ -119,5 +119,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/857xfreeze3/ref/encode.c
