--- supercop-20200826/crypto_core/multsntrup653/avx/ntt.h	2020-08-31 20:12:38.865041988 -0400
+++ supercop-20200826-patched/crypto_core/multsntrup653/avx/ntt.h	2020-08-31 20:09:19.727726607 -0400
@@ -8,9 +8,9 @@
 #define invntt512_7681 CRYPTO_NAMESPACE(invntt512_7681)
 #define invntt512_10753 CRYPTO_NAMESPACE(invntt512_10753)
 
-extern void ntt512_7681(int16_t *,int);
-extern void ntt512_10753(int16_t *,int);
-extern void invntt512_7681(int16_t *,int);
-extern void invntt512_10753(int16_t *,int);
+extern void ntt512_7681(int16_t *f,int reps);
+extern void ntt512_10753(int16_t *f,int reps);
+extern void invntt512_7681(int16_t *f,int reps);
+extern void invntt512_10753(int16_t *f,int reps);
 
 #endif
diff -ru --no-dereference supercop-20200826/crypto_core/multsntrup653/ref/mult.c supercop-20200826-patched/crypto_core/multsntrup653/ref/mult.c
