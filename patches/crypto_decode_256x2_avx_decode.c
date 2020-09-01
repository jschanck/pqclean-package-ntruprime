--- supercop-20200826/crypto_decode/256x2/avx/decode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_decode/256x2/avx/decode.c	2020-09-01 15:35:25.990447957 -0400
@@ -3,7 +3,7 @@
 #include "crypto_decode.h"
 
 #define COPY _mm256_set_epi64x(0x0303030303030303,0x0202020202020202,0x0101010101010101,0x0000000000000000)
-#define MASK _mm256_set1_epi64x(0x8040201008040201)
+#define MASK _mm256_set1_epi64x((int64_t) 0x8040201008040201)
 #define MASK2 _mm256_set1_epi64x(0x0101010101010101)
 
 void crypto_decode(void *v,const unsigned char *s)
diff -ru --no-dereference supercop-20200826/crypto_decode/653x3/avx/decode.c supercop-20200826-patched/crypto_decode/653x3/avx/decode.c
