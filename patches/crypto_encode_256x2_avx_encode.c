--- supercop-20200826/crypto_encode/256x2/avx/encode.c	2020-08-31 09:55:07.069788239 -0400
+++ supercop-20200826-patched/crypto_encode/256x2/avx/encode.c	2020-08-31 07:48:47.718948008 -0400
@@ -30,12 +30,36 @@
   int32_t c5 = _mm256_movemask_epi8(b5);
   int32_t c6 = _mm256_movemask_epi8(b6);
   int32_t c7 = _mm256_movemask_epi8(b7);
-  0[(int32_t *) s] = c0;
-  1[(int32_t *) s] = c1;
-  2[(int32_t *) s] = c2;
-  3[(int32_t *) s] = c3;
-  4[(int32_t *) s] = c4;
-  5[(int32_t *) s] = c5;
-  6[(int32_t *) s] = c6;
-  7[(int32_t *) s] = c7;
+  *s++ = c0; c0 >>= 8;
+  *s++ = c0; c0 >>= 8;
+  *s++ = c0; c0 >>= 8;
+  *s++ = c0;
+  *s++ = c1; c1 >>= 8;
+  *s++ = c1; c1 >>= 8;
+  *s++ = c1; c1 >>= 8;
+  *s++ = c1;
+  *s++ = c2; c2 >>= 8;
+  *s++ = c2; c2 >>= 8;
+  *s++ = c2; c2 >>= 8;
+  *s++ = c2;
+  *s++ = c3; c3 >>= 8;
+  *s++ = c3; c3 >>= 8;
+  *s++ = c3; c3 >>= 8;
+  *s++ = c3;
+  *s++ = c4; c4 >>= 8;
+  *s++ = c4; c4 >>= 8;
+  *s++ = c4; c4 >>= 8;
+  *s++ = c4;
+  *s++ = c5; c5 >>= 8;
+  *s++ = c5; c5 >>= 8;
+  *s++ = c5; c5 >>= 8;
+  *s++ = c5;
+  *s++ = c6; c6 >>= 8;
+  *s++ = c6; c6 >>= 8;
+  *s++ = c6; c6 >>= 8;
+  *s++ = c6;
+  *s++ = c7; c7 >>= 8;
+  *s++ = c7; c7 >>= 8;
+  *s++ = c7; c7 >>= 8;
+  *s++ = c7;
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/653x1541/avx/encode.c supercop-20200826-patched/crypto_encode/653x1541/avx/encode.c