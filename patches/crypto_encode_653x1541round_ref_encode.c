--- supercop-20200826/crypto_encode/653x1541round/ref/encode.c	2020-08-31 20:12:38.949042506 -0400
+++ supercop-20200826-patched/crypto_encode/653x1541round/ref/encode.c	2020-08-31 20:09:19.787727033 -0400
@@ -12,6 +12,6 @@
   int16 x[p];
   int i;
 
-  for (i = 0;i < p;++i) x[i] = 3*((10923*a[i]+16384)>>15);
+  for (i = 0;i < p;++i) x[i] = (int16) (3*((10923*a[i]+16384)>>15));
   crypto_encode_653x1541(out,x);
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/653x3/avx/encode.c supercop-20200826-patched/crypto_encode/653x3/avx/encode.c
