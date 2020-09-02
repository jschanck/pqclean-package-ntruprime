--- supercop-20200826/crypto_kem/sntrup761/factored/params.h
+++ supercop-20200826-patched/crypto_kem/sntrup761/factored/params.h
@@ -5,7 +5,7 @@
 #define q 4591
 #define w 286
 
-#define ppadsort 768
+#define ppadsort 761
 
 #include "crypto_verify_1039.h"
 #define crypto_verify_clen crypto_verify_1039
diff -ru --no-dereference supercop-20200826/crypto_sort/int32/avx2/sort.c supercop-20200826-patched/crypto_sort/int32/avx2/sort.c
