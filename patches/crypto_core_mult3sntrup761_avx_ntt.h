--- supercop-20200826/crypto_core/mult3sntrup761/avx/ntt.h	2020-08-31 09:55:07.021788854 -0400
+++ supercop-20200826-patched/crypto_core/mult3sntrup761/avx/ntt.h	2020-08-31 07:48:47.642996736 -0400
@@ -6,7 +6,7 @@
 #define ntt512_7681 CRYPTO_NAMESPACE(ntt512_7681)
 #define invntt512_7681 CRYPTO_NAMESPACE(invntt512_7681)
 
-extern void ntt512_7681(int16_t *,int);
-extern void invntt512_7681(int16_t *,int);
+extern void ntt512_7681(int16_t *f,int reps);
+extern void invntt512_7681(int16_t *f,int reps);
 
 #endif
diff -ru --no-dereference supercop-20200826/crypto_core/mult3sntrup857/avx/mult1024.c supercop-20200826-patched/crypto_core/mult3sntrup857/avx/mult1024.c
