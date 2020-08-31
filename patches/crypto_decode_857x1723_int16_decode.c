--- supercop-20200826/crypto_decode/857x1723/int16/decode.c	2020-08-31 19:56:55.563747812 -0400
+++ supercop-20200826-patched/crypto_decode/857x1723/int16/decode.c	2020-08-31 20:09:19.771726919 -0400
@@ -41,7 +41,7 @@
   a0 = mulhi(a0,276)-mulhi(lo,743); /* -374...374 */
   a0 += s0; /* -374...629 */
   a0 += (a0>>15)&743; /* 0...742 */
-  a1 = (s1<<8)+s0-a0;
+  a1 = (int16) ((s1<<8)+s0-a0);
   a1 = mullo(a1,-3881);
 
   /* invalid inputs might need reduction mod 14044 */
@@ -61,7 +61,7 @@
   a0 -= 436; /* -670..>37 */
   a0 += (a0>>15)&436; /* -234...435 */
   a0 += (a0>>15)&436; /* 0...435 */
-  a1 = (ri<<6)+((s0-a0)>>2);
+  a1 = (int16) ((ri<<6)+((s0-a0)>>2));
   a1 = mullo(a1,2405);
 
   /* invalid inputs might need reduction mod 8246 */
@@ -79,7 +79,7 @@
     a0 -= 436; /* -670..>37 */
     a0 += (a0>>15)&436; /* -234...435 */
     a0 += (a0>>15)&436; /* 0...435 */
-    a1 = (ri<<6)+((s0-a0)>>2);
+    a1 = (int16) ((ri<<6)+((s0-a0)>>2));
     a1 = mullo(a1,2405);
 
     /* invalid inputs might need reduction mod 436 */
@@ -102,7 +102,7 @@
     a0 -= 334; /* -501..>103 */
     a0 += (a0>>15)&334; /* -167...333 */
     a0 += (a0>>15)&334; /* 0...333 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-22761);
 
     /* invalid inputs might need reduction mod 334 */
@@ -123,7 +123,7 @@
   a0 -= 292; /* -438..>125 */
   a0 += (a0>>15)&292; /* -146...291 */
   a0 += (a0>>15)&292; /* 0...291 */
-  a1 = (ri<<6)+((s0-a0)>>2);
+  a1 = (int16) ((ri<<6)+((s0-a0)>>2));
   a1 = mullo(a1,-3591);
 
   /* invalid inputs might need reduction mod 7229 */
@@ -141,7 +141,7 @@
     a0 -= 292; /* -438..>125 */
     a0 += (a0>>15)&292; /* -146...291 */
     a0 += (a0>>15)&292; /* 0...291 */
-    a1 = (ri<<6)+((s0-a0)>>2);
+    a1 = (int16) ((ri<<6)+((s0-a0)>>2));
     a1 = mullo(a1,-3591);
 
     /* invalid inputs might need reduction mod 292 */
@@ -164,7 +164,7 @@
     a0 -= 273; /* -410..>118 */
     a0 += (a0>>15)&273; /* -137...272 */
     a0 += (a0>>15)&273; /* 0...272 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,4081);
 
     /* invalid inputs might need reduction mod 273 */
@@ -183,7 +183,7 @@
   a0 = mulhi(ri,-259)-mulhi(lo,4225); /* -2178...2112 */
   a0 += s0; /* -2178...2367 */
   a0 += (a0>>15)&4225; /* 0...4224 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,12161);
 
   /* invalid inputs might need reduction mod 438 */
@@ -203,7 +203,7 @@
     a0 = mulhi(a0,-259)-mulhi(lo,4225); /* -2122...2121 */
     a0 += s0; /* -2122...2376 */
     a0 += (a0>>15)&4225; /* 0...4224 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,12161);
 
     /* invalid inputs might need reduction mod 4225 */
@@ -224,7 +224,7 @@
   lo = mullo(a0,-1008);
   a0 = mulhi(a0,16)-mulhi(lo,65); /* -33...32 */
   a0 += (a0>>15)&65; /* 0...64 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,4033);
 
   /* invalid inputs might need reduction mod 1723 */
@@ -264,7 +264,7 @@
     a0 = mulhi(a0,100)-mulhi(lo,2053); /* -1029...1028 */
     a0 += s0; /* -1029...1283 */
     a0 += (a0>>15)&2053; /* 0...2052 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-31539);
 
     /* invalid inputs might need reduction mod 2053 */
@@ -289,7 +289,7 @@
     a0 = mulhi(a0,-3643)-mulhi(lo,11597); /* -6135...6171 */
     a0 += s0; /* -6135...6426 */
     a0 += (a0>>15)&11597; /* 0...11596 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-11387);
 
     /* invalid inputs might need reduction mod 11597 */
@@ -310,7 +310,7 @@
     a0 = mulhi(ri,365)-mulhi(lo,1723); /* -862...952 */
     a0 += s0; /* -862...1207 */
     a0 += (a0>>15)&1723; /* 0...1722 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,20083);
 
     /* invalid inputs might need reduction mod 1723 */
diff -ru --no-dereference supercop-20200826/crypto_decode/857x1723/portable/decode.c supercop-20200826-patched/crypto_decode/857x1723/portable/decode.c
