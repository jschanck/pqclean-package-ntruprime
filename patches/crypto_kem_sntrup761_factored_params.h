--- supercop-20200826/crypto_kem/sntrup761/factored/params.h	2020-08-31 19:56:55.607748540 -0400
+++ supercop-20200826-patched/crypto_kem/sntrup761/factored/params.h	2020-08-31 20:09:19.819727260 -0400
@@ -5,7 +5,7 @@
 #define q 4591
 #define w 286
 
-#define ppadsort 768
+#define ppadsort 761
 
 #include "crypto_verify_1039.h"
 #define crypto_verify_clen crypto_verify_1039
diff -ru --no-dereference supercop-20200826/crypto_verify/1025/avx/verify.c supercop-20200826-patched/crypto_verify/1025/avx/verify.c
