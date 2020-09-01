--- supercop-20200826/crypto_decode/653x4621/int16/decode.c	2020-08-31 20:12:38.909042259 -0400
+++ supercop-20200826-patched/crypto_decode/653x4621/int16/decode.c	2020-08-31 20:09:19.759726834 -0400
@@ -43,7 +43,7 @@
   a0 = mulhi(a0,396)-mulhi(lo,835); /* -421...422 */
   a0 += s0; /* -421...677 */
   a0 += (a0>>15)&835; /* 0...834 */
-  a1 = (s1<<8)+s0-a0;
+  a1 = (int16) ((s1<<8)+s0-a0);
   a1 = mullo(a1,8555);
 
   /* invalid inputs might need reduction mod 6708 */
@@ -67,7 +67,7 @@
     a0 = mulhi(a0,3088)-mulhi(lo,7396); /* -3873...3920 */
     a0 += s0; /* -3873...4175 */
     a0 += (a0>>15)&7396; /* 0...7395 */
-    a1 = (ri<<14)+(s1<<6)+((s0-a0)>>2);
+    a1 = (int16) ((ri<<14)+(s1<<6)+((s0-a0)>>2));
     a1 = mullo(a1,-18679);
 
     /* invalid inputs might need reduction mod 7396 */
@@ -125,7 +125,7 @@
     a0 = mulhi(a0,-14)-mulhi(lo,2370); /* -1186...1185 */
     a0 += s0; /* -1186...1440 */
     a0 += (a0>>15)&2370; /* 0...2369 */
-    a1 = (ri<<15)+(s1<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<15)+(s1<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-8351);
 
     /* invalid inputs might need reduction mod 2370 */
@@ -150,7 +150,7 @@
     a0 = mulhi(a0,4710)-mulhi(lo,12461); /* -6679...6781 */
     a0 += s0; /* -6679...7036 */
     a0 += (a0>>15)&12461; /* 0...12460 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-19675);
 
     /* invalid inputs might need reduction mod 12461 */
@@ -171,7 +171,7 @@
     a0 = mulhi(ri,-468)-mulhi(lo,1786); /* -1010...893 */
     a0 += s0; /* -1010...1148 */
     a0 += (a0>>15)&1786; /* 0...1785 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-12843);
 
     /* invalid inputs might need reduction mod 1786 */
@@ -194,7 +194,7 @@
   a0 = mulhi(a0,248)-mulhi(lo,676); /* -340...340 */
   a0 += s0; /* -340...595 */
   a0 += (a0>>15)&676; /* 0...675 */
-  a1 = (ri<<14)+(s1<<6)+((s0-a0)>>2);
+  a1 = (int16) ((ri<<14)+(s1<<6)+((s0-a0)>>2));
   a1 = mullo(a1,-23655);
 
   /* invalid inputs might need reduction mod 7510 */
@@ -210,7 +210,7 @@
     a0 = mulhi(ri,248)-mulhi(lo,676); /* -338...400 */
     a0 += s0; /* -338...655 */
     a0 += (a0>>15)&676; /* 0...675 */
-    a1 = (ri<<6)+((s0-a0)>>2);
+    a1 = (int16) ((ri<<6)+((s0-a0)>>2));
     a1 = mullo(a1,-23655);
 
     /* invalid inputs might need reduction mod 676 */
@@ -231,7 +231,7 @@
   a0 -= 416; /* -640..>47 */
   a0 += (a0>>15)&416; /* -224...415 */
   a0 += (a0>>15)&416; /* 0...415 */
-  a1 = (ri<<3)+((s0-a0)>>5);
+  a1 = (int16) ((ri<<3)+((s0-a0)>>5));
   a1 = mullo(a1,20165);
 
   /* invalid inputs might need reduction mod 4621 */
@@ -249,7 +249,7 @@
     a0 -= 416; /* -640..>47 */
     a0 += (a0>>15)&416; /* -224...415 */
     a0 += (a0>>15)&416; /* 0...415 */
-    a1 = (ri<<3)+((s0-a0)>>5);
+    a1 = (int16) ((ri<<3)+((s0-a0)>>5));
     a1 = mullo(a1,20165);
 
     /* invalid inputs might need reduction mod 416 */
@@ -272,7 +272,7 @@
     a0 -= 326; /* -501..>92 */
     a0 += (a0>>15)&326; /* -175...325 */
     a0 += (a0>>15)&326; /* 0...325 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-19701);
 
     /* invalid inputs might need reduction mod 326 */
@@ -297,7 +297,7 @@
     a0 = mulhi(a0,-1635)-mulhi(lo,4621); /* -2375...2378 */
     a0 += s0; /* -2375...2633 */
     a0 += (a0>>15)&4621; /* 0...4620 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-29499);
 
     /* invalid inputs might need reduction mod 4621 */
diff -ru --no-dereference supercop-20200826/crypto_decode/653x4621/portable/decode.c supercop-20200826-patched/crypto_decode/653x4621/portable/decode.c
