--- supercop-20200826/crypto_encode/761xint16/ref/encode.c
+++ supercop-20200826-patched/crypto_encode/761xint16/ref/encode.c
@@ -8,7 +8,7 @@
 
   for (i = 0;i < 761;++i) {
     crypto_uint16 u = *x++;
-    *s++ = u;
-    *s++ = u >> 8;
+    *s++ = (unsigned char) u;
+    *s++ = (unsigned char) (u >> 8);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857x1723round/ref/encode.c supercop-20200826-patched/crypto_encode/857x1723round/ref/encode.c
