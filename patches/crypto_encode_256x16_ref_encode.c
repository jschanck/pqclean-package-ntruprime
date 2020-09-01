--- supercop-20200826/crypto_encode/256x16/ref/encode.c	2020-08-31 20:12:38.937042432 -0400
+++ supercop-20200826-patched/crypto_encode/256x16/ref/encode.c	2020-08-31 20:09:19.779726976 -0400
@@ -5,5 +5,5 @@
   const unsigned char *T = v;
   int i;
   for (i = 0;i < 128;++i)
-    s[i] = T[2*i]+(T[2*i+1]<<4);
+    s[i] = (unsigned char) (T[2*i]+(T[2*i+1]<<4));
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/256x2/avx/encode.c supercop-20200826-patched/crypto_encode/256x2/avx/encode.c
