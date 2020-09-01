--- supercop-20200826/crypto_decode/653x3/avx/decode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_decode/653x3/avx/decode.c	2020-09-01 15:38:39.382804963 -0400
@@ -63,5 +63,5 @@
     nextf += 128;
   }
 
-  *f = ((uint8)(*s&3))-1;
+  *f = (uint8) ((*s&3)-1);
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/653x3/ref/decode.c supercop-20200826-patched/crypto_decode/653x3/ref/decode.c
