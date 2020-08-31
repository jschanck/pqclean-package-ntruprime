--- supercop-20200826/crypto_encode/653x1541/portable/encode.c	2020-08-31 09:55:07.073788188 -0400
+++ supercop-20200826-patched/crypto_encode/653x1541/portable/encode.c	2020-08-31 07:48:47.726942877 -0400
@@ -110,5 +110,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/653x1541round/avx/encode.c supercop-20200826-patched/crypto_encode/653x1541round/avx/encode.c
