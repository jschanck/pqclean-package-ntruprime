--- supercop-20200826/crypto_encode/857x1723/portable/encode.c	2020-08-31 09:55:07.097787881 -0400
+++ supercop-20200826-patched/crypto_encode/857x1723/portable/encode.c	2020-08-31 07:48:47.758922360 -0400
@@ -114,5 +114,5 @@
   R[0] = r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857x1723round/avx/encode.c supercop-20200826-patched/crypto_encode/857x1723round/avx/encode.c
