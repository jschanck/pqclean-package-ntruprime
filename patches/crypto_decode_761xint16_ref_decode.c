--- supercop-20200826/crypto_decode/761xint16/ref/decode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_decode/761xint16/ref/decode.c	2020-09-01 15:35:25.994447942 -0400
@@ -9,8 +9,7 @@
   for (i = 0;i < 761;++i) {
     crypto_uint16 u0 = s[0];
     crypto_uint16 u1 = s[1];
-    u1 <<= 8;
-    *x = u0 | u1;
+    *x = (crypto_uint16) (u0 | (u1<<8));
     x += 1;
     s += 2;
   }
diff -ru --no-dereference supercop-20200826/crypto_decode/857x3/avx/decode.c supercop-20200826-patched/crypto_decode/857x3/avx/decode.c
