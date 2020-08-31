--- supercop-20200826/crypto_decode/int16/ref/decode.c	2020-08-31 19:56:55.571747944 -0400
+++ supercop-20200826-patched/crypto_decode/int16/ref/decode.c	2020-08-31 20:09:19.779726976 -0400
@@ -5,6 +5,6 @@
 {
   crypto_uint16 u0 = s[0];
   crypto_uint16 u1 = s[1];
-  u1 <<= 8;
+  u1 = (crypto_uint16) (u1 << 8);
   *(crypto_uint16 *) x = u0 | u1;
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/256x16/ref/encode.c supercop-20200826-patched/crypto_encode/256x16/ref/encode.c