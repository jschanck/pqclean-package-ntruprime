--- supercop-20200826/crypto_encode/857x3/avx/encode.c	2020-08-28 13:06:31.013178966 -0400
+++ supercop-20200826-patched/crypto_encode/857x3/avx/encode.c	2020-08-28 12:38:23.485144792 -0400
@@ -7,13 +7,17 @@
 #define loops 7
 #define overshoot 10
 
-static const __attribute((aligned(32))) uint8 lobytes_buf[32] = {
-  255,0,255,0,255,0,255,0,
-  255,0,255,0,255,0,255,0,
-  255,0,255,0,255,0,255,0,
-  255,0,255,0,255,0,255,0,
+static const union {
+  uint8 init[32];
+  __m256i val;
+} lobytes_buf = { .init = {
+    255,0,255,0,255,0,255,0,
+    255,0,255,0,255,0,255,0,
+    255,0,255,0,255,0,255,0,
+    255,0,255,0,255,0,255,0,
+  }
 };
-#define lobytes (*(__m256i *) lobytes_buf)
+#define lobytes (lobytes_buf.val)
 
 void crypto_encode(unsigned char *s,const void *v)
 {
diff -ru --no-dereference supercop-20200826/crypto_encode/857x5167/avx/encode.c supercop-20200826-patched/crypto_encode/857x5167/avx/encode.c
