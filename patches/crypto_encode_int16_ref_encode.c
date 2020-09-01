--- supercop-20200826/crypto_encode/int16/ref/encode.c	2020-08-31 20:12:38.993042777 -0400
+++ supercop-20200826-patched/crypto_encode/int16/ref/encode.c	2020-08-31 20:09:19.815727231 -0400
@@ -1,9 +1,10 @@
 #include "crypto_encode.h"
 #include "crypto_uint16.h"
+#define uint16 crypto_uint16
 
 void crypto_encode(unsigned char *s,const void *x)
 {
-  crypto_uint16 u = *(const crypto_uint16 *) x;
-  s[0] = u;
-  s[1] = u >> 8;
+  uint16 u = *(const uint16 *) x;
+  s[0] = (unsigned char) u;
+  s[1] = (unsigned char) (u >> 8);
 }
diff -ru --no-dereference supercop-20200826/crypto_kem/ntrulpr761/factored/kem.c supercop-20200826-patched/crypto_kem/ntrulpr761/factored/kem.c
