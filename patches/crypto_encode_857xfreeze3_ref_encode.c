--- supercop-20200826/crypto_encode/857xfreeze3/ref/encode.c	2020-08-31 09:55:07.105787778 -0400
+++ supercop-20200826-patched/crypto_encode/857xfreeze3/ref/encode.c	2020-08-31 07:48:47.770914667 -0400
@@ -11,7 +11,7 @@
 /* all inputs: 3 divides x-F3_freeze(x) */
 /* and F3_freeze(x) is in {-2,-1,0,1,2} */
 
-static inline char F3_freeze(int16 x)
+static inline unsigned char F3_freeze(int16 x)
 {
   return x-3*((10923*x+16384)>>15);
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/int16/ref/encode.c supercop-20200826-patched/crypto_encode/int16/ref/encode.c