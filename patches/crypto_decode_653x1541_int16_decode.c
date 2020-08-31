--- supercop-20200826/crypto_decode/653x1541/int16/decode.c	2020-08-31 19:56:55.551747613 -0400
+++ supercop-20200826-patched/crypto_decode/653x1541/int16/decode.c	2020-08-31 20:09:19.755726805 -0400
@@ -41,7 +41,7 @@
   lo = mullo(a0,-923);
   a0 = mulhi(a0,3)-mulhi(lo,71); /* -36...35 */
   a0 += (a0>>15)&71; /* 0...70 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,-22153);
 
   /* invalid inputs might need reduction mod 9402 */
@@ -63,7 +63,7 @@
     lo = mullo(a0,-489);
     a0 = mulhi(a0,10)-mulhi(lo,134); /* -68...67 */
     a0 += (a0>>15)&134; /* 0...133 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,19563);
 
     /* invalid inputs might need reduction mod 134 */
@@ -82,7 +82,7 @@
   a0 = mulhi(ri,1223)-mulhi(lo,2953); /* -1477...1782 */
   a0 += s0; /* -1477...2037 */
   a0 += (a0>>15)&2953; /* 0...2952 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,-9543);
 
   /* invalid inputs might need reduction mod 815 */
@@ -102,7 +102,7 @@
     a0 = mulhi(a0,1223)-mulhi(lo,2953); /* -1505...1514 */
     a0 += s0; /* -1505...1769 */
     a0 += (a0>>15)&2953; /* 0...2952 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-9543);
 
     /* invalid inputs might need reduction mod 2953 */
@@ -127,7 +127,7 @@
     a0 = mulhi(a0,1756)-mulhi(lo,13910); /* -7142...7159 */
     a0 += s0; /* -7142...7414 */
     a0 += (a0>>15)&13910; /* 0...13909 */
-    a1 = (ri<<15)+(s1<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<15)+(s1<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-13437);
 
     /* invalid inputs might need reduction mod 13910 */
@@ -148,7 +148,7 @@
     a0 = mulhi(ri,-101)-mulhi(lo,1887); /* -969...943 */
     a0 += s0; /* -969...1198 */
     a0 += (a0>>15)&1887; /* 0...1886 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,5279);
 
     /* invalid inputs might need reduction mod 1887 */
@@ -169,7 +169,7 @@
     a0 = mulhi(ri,-84)-mulhi(lo,695); /* -369...347 */
     a0 += s0; /* -369...602 */
     a0 += (a0>>15)&695; /* 0...694 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,31495);
 
     /* invalid inputs might need reduction mod 695 */
@@ -192,7 +192,7 @@
   a0 = mulhi(a0,2401)-mulhi(lo,6745); /* -3497...3527 */
   a0 += s0; /* -3497...3782 */
   a0 += (a0>>15)&6745; /* 0...6744 */
-  a1 = (s1<<8)+s0-a0;
+  a1 = (int16) ((s1<<8)+s0-a0);
   a1 = mullo(a1,-29207);
 
   /* invalid inputs might need reduction mod 7910 */
@@ -212,7 +212,7 @@
     a0 = mulhi(a0,2401)-mulhi(lo,6745); /* -3497...3527 */
     a0 += s0; /* -3497...3782 */
     a0 += (a0>>15)&6745; /* 0...6744 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-29207);
 
     /* invalid inputs might need reduction mod 6745 */
@@ -231,7 +231,7 @@
   a0 = mulhi(ri,64)-mulhi(lo,1314); /* -657...673 */
   a0 += s0; /* -657...928 */
   a0 += (a0>>15)&1314; /* 0...1313 */
-  a1 = (ri<<7)+((s0-a0)>>1);
+  a1 = (int16) ((ri<<7)+((s0-a0)>>1));
   a1 = mullo(a1,-399);
 
   /* invalid inputs might need reduction mod 1541 */
@@ -247,7 +247,7 @@
     a0 = mulhi(ri,64)-mulhi(lo,1314); /* -657...673 */
     a0 += s0; /* -657...928 */
     a0 += (a0>>15)&1314; /* 0...1313 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-399);
 
     /* invalid inputs might need reduction mod 1314 */
@@ -272,7 +272,7 @@
     a0 = mulhi(a0,4400)-mulhi(lo,9277); /* -4950...5040 */
     a0 += s0; /* -4950...5295 */
     a0 += (a0>>15)&9277; /* 0...9276 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-27883);
 
     /* invalid inputs might need reduction mod 9277 */
@@ -293,7 +293,7 @@
     a0 = mulhi(ri,349)-mulhi(lo,1541); /* -771...857 */
     a0 += s0; /* -771...1112 */
     a0 += (a0>>15)&1541; /* 0...1540 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,-10547);
 
     /* invalid inputs might need reduction mod 1541 */
diff -ru --no-dereference supercop-20200826/crypto_decode/653x1541/portable/decode.c supercop-20200826-patched/crypto_decode/653x1541/portable/decode.c
