--- supercop-20200826/crypto_core/mult3sntrup761/avx/ntt.h	2020-08-31 19:56:55.511746950 -0400
+++ supercop-20200826-patched/crypto_core/mult3sntrup761/avx/ntt.h	2020-08-31 20:09:19.715726522 -0400
@@ -6,7 +6,7 @@
 #define ntt512_7681 CRYPTO_NAMESPACE(ntt512_7681)
 #define invntt512_7681 CRYPTO_NAMESPACE(invntt512_7681)
 
-extern void ntt512_7681(int16_t *,int);
-extern void invntt512_7681(int16_t *,int);
+extern void ntt512_7681(int16_t *f,int reps);
+extern void invntt512_7681(int16_t *f,int reps);
 
 #endif
diff -ru --no-dereference supercop-20200826/crypto_core/mult3sntrup761/ref/mult.c supercop-20200826-patched/crypto_core/mult3sntrup761/ref/mult.c
