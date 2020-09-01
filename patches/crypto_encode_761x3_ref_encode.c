--- supercop-20200826/crypto_encode/761x3/ref/encode.c	2020-08-31 20:12:38.969042629 -0400
+++ supercop-20200826-patched/crypto_encode/761x3/ref/encode.c	2020-08-31 20:09:19.799727118 -0400
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
diff -ru --no-dereference supercop-20200826/crypto_encode/761x4591/avx/encode.c supercop-20200826-patched/crypto_encode/761x4591/avx/encode.c
