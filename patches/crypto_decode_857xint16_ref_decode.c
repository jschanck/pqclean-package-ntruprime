--- supercop-20200826/crypto_decode/857xint16/ref/decode.c	2020-08-31 19:56:55.571747944 -0400
+++ supercop-20200826-patched/crypto_decode/857xint16/ref/decode.c	2020-08-31 20:09:19.775726948 -0400
@@ -9,8 +9,7 @@
   for (i = 0;i < 857;++i) {
     crypto_uint16 u0 = s[0];
     crypto_uint16 u1 = s[1];
-    u1 <<= 8;
-    *x = u0 | u1;
+    *x = (crypto_uint16) (u0 | (u1<<8));
     x += 1;
     s += 2;
   }
diff -ru --no-dereference supercop-20200826/crypto_decode/int16/ref/decode.c supercop-20200826-patched/crypto_decode/int16/ref/decode.c