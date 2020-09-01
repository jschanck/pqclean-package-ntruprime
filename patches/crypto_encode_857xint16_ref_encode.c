--- supercop-20200826/crypto_encode/857xint16/ref/encode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_encode/857xint16/ref/encode.c	2020-09-01 15:35:26.038447779 -0400
@@ -8,7 +8,7 @@
 
   for (i = 0;i < 857;++i) {
     crypto_uint16 u = *x++;
-    *s++ = u;
-    *s++ = u >> 8;
+    *s++ = (unsigned char) u;
+    *s++ = (unsigned char) (u >> 8);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/int16/ref/encode.c supercop-20200826-patched/crypto_encode/int16/ref/encode.c
