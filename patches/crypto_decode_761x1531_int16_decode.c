--- supercop-20200826/crypto_decode/761x1531/int16/decode.c	2020-08-31 19:56:55.559747745 -0400
+++ supercop-20200826-patched/crypto_decode/761x1531/int16/decode.c	2020-08-31 20:09:19.763726863 -0400
@@ -39,7 +39,7 @@
   a0 = mulhi(ri,60)-mulhi(lo,593); /* -297...311 */
   a0 += s0; /* -297...566 */
   a0 += (a0>>15)&593; /* 0...592 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,-31055);
 
   /* invalid inputs might need reduction mod 1500 */
@@ -63,7 +63,7 @@
     a0 = mulhi(a0,672)-mulhi(lo,6232); /* -3148...3152 */
     a0 += s0; /* -3148...3407 */
     a0 += (a0>>15)&6232; /* 0...6231 */
-    a1 = (ri<<13)+(s1<<5)+((s0-a0)>>3);
+    a1 = (int16) ((ri<<13)+(s1<<5)+((s0-a0)>>3));
     a1 = mullo(a1,12451);
 
     /* invalid inputs might need reduction mod 6232 */
@@ -82,7 +82,7 @@
   a0 = mulhi(ri,-476)-mulhi(lo,1263); /* -751...631 */
   a0 += s0; /* -751...886 */
   a0 += (a0>>15)&1263; /* 0...1262 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,-22001);
 
   /* invalid inputs might need reduction mod 304 */
@@ -98,7 +98,7 @@
     a0 = mulhi(ri,-476)-mulhi(lo,1263); /* -751...631 */
     a0 += s0; /* -751...886 */
     a0 += (a0>>15)&1263; /* 0...1262 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,-22001);
 
     /* invalid inputs might need reduction mod 1263 */
@@ -121,7 +121,7 @@
   a0 = mulhi(a0,2348)-mulhi(lo,9097); /* -4712...4741 */
   a0 += s0; /* -4712...4996 */
   a0 += (a0>>15)&9097; /* 0...9096 */
-  a1 = (s1<<8)+s0-a0;
+  a1 = (int16) ((s1<<8)+s0-a0);
   a1 = mullo(a1,17081);
 
   /* invalid inputs might need reduction mod 2188 */
@@ -141,7 +141,7 @@
     a0 = mulhi(a0,2348)-mulhi(lo,9097); /* -4712...4741 */
     a0 += s0; /* -4712...4996 */
     a0 += (a0>>15)&9097; /* 0...9096 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,17081);
 
     /* invalid inputs might need reduction mod 9097 */
@@ -160,7 +160,7 @@
   a0 = mulhi(ri,372)-mulhi(lo,1526); /* -763...856 */
   a0 += s0; /* -763...1111 */
   a0 += (a0>>15)&1526; /* 0...1525 */
-  a1 = (ri<<7)+((s0-a0)>>1);
+  a1 = (int16) ((ri<<7)+((s0-a0)>>1));
   a1 = mullo(a1,-18381);
 
   /* invalid inputs might need reduction mod 367 */
@@ -176,7 +176,7 @@
     a0 = mulhi(ri,372)-mulhi(lo,1526); /* -763...856 */
     a0 += s0; /* -763...1111 */
     a0 += (a0>>15)&1526; /* 0...1525 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-18381);
 
     /* invalid inputs might need reduction mod 1526 */
@@ -195,7 +195,7 @@
   a0 = mulhi(ri,-284)-mulhi(lo,625); /* -384...312 */
   a0 += s0; /* -384...567 */
   a0 += (a0>>15)&625; /* 0...624 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,32401);
 
   /* invalid inputs might need reduction mod 150 */
@@ -211,7 +211,7 @@
     a0 = mulhi(ri,-284)-mulhi(lo,625); /* -384...312 */
     a0 += s0; /* -384...567 */
     a0 += (a0>>15)&625; /* 0...624 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,32401);
 
     /* invalid inputs might need reduction mod 625 */
@@ -234,7 +234,7 @@
   a0 = mulhi(a0,2816)-mulhi(lo,6400); /* -3338...3378 */
   a0 += s0; /* -3338...3633 */
   a0 += (a0>>15)&6400; /* 0...6399 */
-  a1 = (ri<<8)+s1+((s0-a0)>>8);
+  a1 = (int16) ((ri<<8)+s1+((s0-a0)>>8));
   a1 = mullo(a1,23593);
 
   /* invalid inputs might need reduction mod 1531 */
@@ -254,7 +254,7 @@
     a0 = mulhi(a0,2816)-mulhi(lo,6400); /* -3338...3378 */
     a0 += s0; /* -3338...3633 */
     a0 += (a0>>15)&6400; /* 0...6399 */
-    a1 = (ri<<8)+s1+((s0-a0)>>8);
+    a1 = (int16) ((ri<<8)+s1+((s0-a0)>>8));
     a1 = mullo(a1,23593);
 
     /* invalid inputs might need reduction mod 6400 */
@@ -300,7 +300,7 @@
     a0 = mulhi(a0,1592)-mulhi(lo,9157); /* -4690...4705 */
     a0 += s0; /* -4690...4960 */
     a0 += (a0>>15)&9157; /* 0...9156 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,25357);
 
     /* invalid inputs might need reduction mod 9157 */
@@ -321,7 +321,7 @@
     a0 = mulhi(ri,518)-mulhi(lo,1531); /* -766...895 */
     a0 += s0; /* -766...1150 */
     a0 += (a0>>15)&1531; /* 0...1530 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,15667);
 
     /* invalid inputs might need reduction mod 1531 */
diff -ru --no-dereference supercop-20200826/crypto_decode/761x1531/portable/decode.c supercop-20200826-patched/crypto_decode/761x1531/portable/decode.c
