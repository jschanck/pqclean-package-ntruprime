--- supercop-20200826/crypto_kem/sntrup761/factored/params.h	2020-08-25 20:27:06.000000000 -0400
+++ supercop-20200826-patched/crypto_kem/sntrup761/factored/params.h	2020-08-31 09:59:57.960728736 -0400
@@ -5,7 +5,7 @@
 #define q 4591
 #define w 286
 
-#define ppadsort 768
+#define ppadsort 761
 
 #include "crypto_verify_1039.h"
 #define crypto_verify_clen crypto_verify_1039
diff -ru --no-dereference supercop-20200826/crypto_verify/1025/avx/verify.c supercop-20200826-patched/crypto_verify/1025/avx/verify.c