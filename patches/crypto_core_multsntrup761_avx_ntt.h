--- supercop-20200826/crypto_core/multsntrup761/avx/ntt.h	2020-08-28 13:06:30.977178972 -0400
+++ supercop-20200826-patched/crypto_core/multsntrup761/avx/ntt.h	2020-08-28 12:38:23.441144768 -0400
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
diff -ru --no-dereference supercop-20200826/crypto_core/multsntrup857/avx/mult1024.c supercop-20200826-patched/crypto_core/multsntrup857/avx/mult1024.c
