--- supercop-20200826/crypto_encode/256x2/ref/encode.c	2020-08-31 19:56:55.575748009 -0400
+++ supercop-20200826-patched/crypto_encode/256x2/ref/encode.c	2020-08-31 20:09:19.783727004 -0400
@@ -5,5 +5,5 @@
   const unsigned char *r = v;
   int i;
   for (i = 0;i < 32;++i) s[i] = 0;
-  for (i = 0;i < 256;++i) s[i>>3] |= (r[i]&1)<<(i&7);
+  for (i = 0;i < 256;++i) s[i>>3] |= (unsigned char) ((r[i]&1)<<(i&7));
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/653x1541/avx/encode.c supercop-20200826-patched/crypto_encode/653x1541/avx/encode.c
