--- supercop-20200826/crypto_core/multsntrup857/ref/mult.c	2020-08-31 19:56:55.535747347 -0400
+++ supercop-20200826-patched/crypto_core/multsntrup857/ref/mult.c	2020-08-31 20:09:19.739726692 -0400
@@ -17,7 +17,7 @@
 {
   x -= q*((q18*x)>>18);
   x -= q*((q27*x+67108864)>>27);
-  return x;
+  return (Fq) x;
 }
 
 int crypto_core(unsigned char *outbytes,const unsigned char *inbytes,const unsigned char *kbytes,const unsigned char *cbytes)
@@ -33,9 +33,9 @@
     f[i] = Fq_freeze(f[i]);
 
   for (i = 0;i < p;++i) {
-    small gi = kbytes[i];
+    small gi = (small) kbytes[i];
     small gi0 = gi&1;
-    g[i] = gi0-(gi&(gi0<<1));
+    g[i] = (small) (gi0-(gi&(gi0<<1)));
   }
 
   for (i = 0;i < p;++i) {
diff -ru --no-dereference supercop-20200826/crypto_core/weightsntrup653/avx/weight.c supercop-20200826-patched/crypto_core/weightsntrup653/avx/weight.c
