--- supercop-20200826/crypto_encode/857x3/ref/encode.c	2020-08-31 19:56:55.599748407 -0400
+++ supercop-20200826-patched/crypto_encode/857x3/ref/encode.c	2020-08-31 20:09:19.811727204 -0400
@@ -12,9 +12,9 @@
 
   for (i = 0;i < p/4;++i) {
     x = *f++ + 1;
-    x += (*f++ + 1)<<2;
-    x += (*f++ + 1)<<4;
-    x += (*f++ + 1)<<6;
+    x += (uint8) ((*f++ + 1)<<2);
+    x += (uint8) ((*f++ + 1)<<4);
+    x += (uint8) ((*f++ + 1)<<6);
     *s++ = x;
   }
   x = *f++ + 1;
diff -ru --no-dereference supercop-20200826/crypto_encode/857x5167/avx/encode.c supercop-20200826-patched/crypto_encode/857x5167/avx/encode.c
