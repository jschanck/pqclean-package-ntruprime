--- supercop-20200826/crypto_encode/761xint16/ref/encode.c	2020-08-31 20:12:38.977042679 -0400
+++ supercop-20200826-patched/crypto_encode/761xint16/ref/encode.c	2020-08-31 20:09:19.803727146 -0400
@@ -8,7 +8,7 @@
 
   for (i = 0;i < 761;++i) {
     crypto_uint16 u = *x++;
-    *s++ = u;
-    *s++ = u >> 8;
+    *s++ = (unsigned char) u;
+    *s++ = (unsigned char) (u >> 8);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857x1723/avx/encode.c supercop-20200826-patched/crypto_encode/857x1723/avx/encode.c
