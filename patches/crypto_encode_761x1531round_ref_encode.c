--- supercop-20200826/crypto_encode/761x1531round/ref/encode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_encode/761x1531round/ref/encode.c	2020-09-01 15:35:26.018447853 -0400
@@ -12,6 +12,6 @@
   int16 x[p];
   int i;
 
-  for (i = 0;i < p;++i) x[i] = 3*((10923*a[i]+16384)>>15);
+  for (i = 0;i < p;++i) x[i] = (int16) (3*((10923*a[i]+16384)>>15));
   crypto_encode_761x1531(out,x);
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/761x3/avx/encode.c supercop-20200826-patched/crypto_encode/761x3/avx/encode.c
