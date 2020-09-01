--- supercop-20200826/crypto_encode/256x16/ref/encode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_encode/256x16/ref/encode.c	2020-09-01 15:35:26.002447912 -0400
@@ -5,5 +5,5 @@
   const unsigned char *T = v;
   int i;
   for (i = 0;i < 128;++i)
-    s[i] = T[2*i]+(T[2*i+1]<<4);
+    s[i] = (unsigned char) (T[2*i]+(T[2*i+1]<<4));
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/256x2/avx/encode.c supercop-20200826-patched/crypto_encode/256x2/avx/encode.c
