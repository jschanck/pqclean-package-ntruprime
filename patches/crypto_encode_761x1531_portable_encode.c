--- supercop-20200826/crypto_encode/761x1531/portable/encode.c	2020-08-31 09:55:07.085788034 -0400
+++ supercop-20200826-patched/crypto_encode/761x1531/portable/encode.c	2020-08-31 07:48:47.742932619 -0400
@@ -103,5 +103,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/761x1531round/avx/encode.c supercop-20200826-patched/crypto_encode/761x1531round/avx/encode.c
