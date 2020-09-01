--- supercop-20200826/crypto_encode/761x3/ref/encode.c
+++ supercop-20200826-patched/crypto_encode/761x3/ref/encode.c
@@ -6,15 +6,15 @@
 
 void crypto_encode(unsigned char *s,const void *v)
 {
-  const uint8 *f = v;
+  const uint8 *f = (const uint8 *)v;
   uint8 x;
   int i;
 
   for (i = 0;i < p/4;++i) {
-    x = *f++ + 1;
-    x += (*f++ + 1)<<2;
-    x += (*f++ + 1)<<4;
-    x += (*f++ + 1)<<6;
+    x = (uint8) (*f++ + 1);
+    x = (uint8) (x + ((*f++ + 1)<<2));
+    x = (uint8) (x + ((*f++ + 1)<<4));
+    x = (uint8) (x + ((*f++ + 1)<<6));
     *s++ = x;
   }
   x = *f++ + 1;
diff -ru --no-dereference supercop-20200826/crypto_encode/761xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/761xfreeze3/ref/encode.c
