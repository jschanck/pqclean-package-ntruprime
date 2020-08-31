--- supercop-20200826/crypto_encode/653x4621/portable/encode.c	2020-08-31 09:55:07.081788085 -0400
+++ supercop-20200826-patched/crypto_encode/653x4621/portable/encode.c	2020-08-31 07:48:47.738935183 -0400
@@ -110,5 +110,5 @@
   R[0] = r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/653xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/653xfreeze3/ref/encode.c
