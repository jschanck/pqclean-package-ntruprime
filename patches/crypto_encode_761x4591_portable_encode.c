--- supercop-20200826/crypto_encode/761x4591/portable/encode.c	2020-08-31 09:55:07.093787931 -0400
+++ supercop-20200826-patched/crypto_encode/761x4591/portable/encode.c	2020-08-31 07:48:47.754924926 -0400
@@ -125,5 +125,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/761xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/761xfreeze3/ref/encode.c
