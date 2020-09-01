--- supercop-20200826/crypto_decode/653xint16/ref/decode.c
+++ supercop-20200826-patched/crypto_decode/653xint16/ref/decode.c
@@ -9,8 +9,7 @@
   for (i = 0;i < 653;++i) {
     crypto_uint16 u0 = s[0];
     crypto_uint16 u1 = s[1];
-    u1 <<= 8;
-    *x = u0 | u1;
+    *x = (crypto_uint16) (u0 | (u1<<8));
     x += 1;
     s += 2;
   }
diff -ru --no-dereference supercop-20200826/crypto_decode/761x3/avx/decode.c supercop-20200826-patched/crypto_decode/761x3/avx/decode.c
