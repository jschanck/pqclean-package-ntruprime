--- supercop-20200826/crypto_encode/653x3/ref/encode.c
+++ supercop-20200826-patched/crypto_encode/653x3/ref/encode.c
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
diff -ru --no-dereference supercop-20200826/crypto_encode/653xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/653xfreeze3/ref/encode.c
