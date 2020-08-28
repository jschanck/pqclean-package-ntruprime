--- supercop-20200826/crypto_encode/761x1531/portable/encode.c	2020-08-28 13:06:31.001178968 -0400
+++ supercop-20200826-patched/crypto_encode/761x1531/portable/encode.c	2020-08-28 12:38:23.477144788 -0400
@@ -103,5 +103,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/761x1531round/avx/encode.c supercop-20200826-patched/crypto_encode/761x1531round/avx/encode.c
