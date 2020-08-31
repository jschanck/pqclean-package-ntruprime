--- supercop-20200826/crypto_encode/653xfreeze3/ref/encode.c	2020-08-31 19:56:55.583748143 -0400
+++ supercop-20200826-patched/crypto_encode/653xfreeze3/ref/encode.c	2020-08-31 20:09:19.791727061 -0400
@@ -11,9 +11,9 @@
 /* all inputs: 3 divides x-F3_freeze(x) */
 /* and F3_freeze(x) is in {-2,-1,0,1,2} */
 
-static inline char F3_freeze(int16 x)
+static inline unsigned char F3_freeze(int16 x)
 {
-  return x-3*((10923*x+16384)>>15);
+  return (unsigned char) (x-3*((10923*x+16384)>>15));
 }
 
 void crypto_encode(unsigned char *s,const void *v)
diff -ru --no-dereference supercop-20200826/crypto_encode/653xint16/ref/encode.c supercop-20200826-patched/crypto_encode/653xint16/ref/encode.c
