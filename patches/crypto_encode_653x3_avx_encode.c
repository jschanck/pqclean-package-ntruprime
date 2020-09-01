--- supercop-20200826/crypto_encode/653x3/avx/encode.c	2020-08-25 20:26:58.000000000 -0400
+++ supercop-20200826-patched/crypto_encode/653x3/avx/encode.c	2020-09-01 15:35:26.010447883 -0400
@@ -7,13 +7,17 @@
 #define loops 6
 #define overshoot 29
 
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
diff -ru --no-dereference supercop-20200826/crypto_encode/653x3/ref/encode.c supercop-20200826-patched/crypto_encode/653x3/ref/encode.c
