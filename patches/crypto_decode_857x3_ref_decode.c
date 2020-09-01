--- supercop-20200826/crypto_decode/857x3/ref/decode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_decode/857x3/ref/decode.c	2020-09-01 15:37:37.194672343 -0400
@@ -12,11 +12,11 @@
 
   for (i = 0;i < p/4;++i) {
     x = *s++;
-    *f++ = ((uint8)(x&3))-1; x >>= 2;
-    *f++ = ((uint8)(x&3))-1; x >>= 2;
-    *f++ = ((uint8)(x&3))-1; x >>= 2;
-    *f++ = ((uint8)(x&3))-1;
+    *f++ = (uint8) ((x&3)-1); x >>= 2;
+    *f++ = (uint8) ((x&3)-1); x >>= 2;
+    *f++ = (uint8) ((x&3)-1); x >>= 2;
+    *f++ = (uint8) ((x&3)-1);
   }
   x = *s++;
-  *f++ = ((uint8)(x&3))-1;
+  *f++ = (uint8) ((x&3)-1);
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/857xint16/ref/decode.c supercop-20200826-patched/crypto_decode/857xint16/ref/decode.c
