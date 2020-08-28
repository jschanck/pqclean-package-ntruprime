--- supercop-20200826/crypto_encode/857x1723/portable/encode.c	2020-08-28 13:06:31.009178967 -0400
+++ supercop-20200826-patched/crypto_encode/857x1723/portable/encode.c	2020-08-28 12:38:23.485144792 -0400
@@ -114,5 +114,5 @@
   R[0] = r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857x1723round/avx/encode.c supercop-20200826-patched/crypto_encode/857x1723round/avx/encode.c
