--- supercop-20200826/crypto_decode/761x4591/int16/decode.c	2020-08-31 19:56:55.559747745 -0400
+++ supercop-20200826-patched/crypto_decode/761x4591/int16/decode.c	2020-08-31 20:09:19.767726890 -0400
@@ -43,7 +43,7 @@
   a0 = mulhi(a0,-3624)-mulhi(lo,9470); /* -5011...5046 */
   a0 += s0; /* -5011...5301 */
   a0 += (a0>>15)&9470; /* 0...9469 */
-  a1 = (ri<<15)+(s1<<7)+((s0-a0)>>1);
+  a1 = (int16) ((ri<<15)+(s1<<7)+((s0-a0)>>1));
   a1 = mullo(a1,-21121);
 
   /* invalid inputs might need reduction mod 11127 */
@@ -63,7 +63,7 @@
     a0 = mulhi(ri,541)-mulhi(lo,1557); /* -779...913 */
     a0 += s0; /* -779...1168 */
     a0 += (a0>>15)&1557; /* 0...1556 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,-26307);
 
     /* invalid inputs might need reduction mod 1557 */
@@ -82,7 +82,7 @@
   a0 = mulhi(ri,-545)-mulhi(lo,10101); /* -5187...5050 */
   a0 += s0; /* -5187...5305 */
   a0 += (a0>>15)&10101; /* 0...10100 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,12509);
 
   /* invalid inputs might need reduction mod 282 */
@@ -102,7 +102,7 @@
     a0 = mulhi(a0,-545)-mulhi(lo,10101); /* -5095...5093 */
     a0 += s0; /* -5095...5348 */
     a0 += (a0>>15)&10101; /* 0...10100 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,12509);
 
     /* invalid inputs might need reduction mod 10101 */
@@ -125,7 +125,7 @@
   a0 = mulhi(a0,-656)-mulhi(lo,1608); /* -815...813 */
   a0 += s0; /* -815...1068 */
   a0 += (a0>>15)&1608; /* 0...1607 */
-  a1 = (ri<<13)+(s1<<5)+((s0-a0)>>3);
+  a1 = (int16) ((ri<<13)+(s1<<5)+((s0-a0)>>3));
   a1 = mullo(a1,6521);
 
   /* invalid inputs might need reduction mod 11468 */
@@ -141,7 +141,7 @@
     a0 = mulhi(ri,-656)-mulhi(lo,1608); /* -968...804 */
     a0 += s0; /* -968...1059 */
     a0 += (a0>>15)&1608; /* 0...1607 */
-    a1 = (ri<<5)+((s0-a0)>>3);
+    a1 = (int16) ((ri<<5)+((s0-a0)>>3));
     a1 = mullo(a1,6521);
 
     /* invalid inputs might need reduction mod 1608 */
@@ -160,7 +160,7 @@
   a0 = mulhi(ri,4206)-mulhi(lo,10265); /* -5133...6184 */
   a0 += s0; /* -5133...6439 */
   a0 += (a0>>15)&10265; /* 0...10264 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,-19415);
 
   /* invalid inputs might need reduction mod 286 */
@@ -180,7 +180,7 @@
     a0 = mulhi(a0,4206)-mulhi(lo,10265); /* -5462...5545 */
     a0 += s0; /* -5462...5800 */
     a0 += (a0>>15)&10265; /* 0...10264 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-19415);
 
     /* invalid inputs might need reduction mod 10265 */
@@ -203,7 +203,7 @@
   a0 = mulhi(a0,-134)-mulhi(lo,1621); /* -813...812 */
   a0 += s0; /* -813...1067 */
   a0 += (a0>>15)&1621; /* 0...1620 */
-  a1 = (s1<<8)+s0-a0;
+  a1 = (int16) ((s1<<8)+s0-a0);
   a1 = mullo(a1,-14595);
 
   /* invalid inputs might need reduction mod 11550 */
@@ -219,7 +219,7 @@
     a0 = mulhi(ri,-134)-mulhi(lo,1621); /* -844...810 */
     a0 += s0; /* -844...1065 */
     a0 += (a0>>15)&1621; /* 0...1620 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,-14595);
 
     /* invalid inputs might need reduction mod 1621 */
@@ -238,7 +238,7 @@
   a0 = mulhi(ri,-272)-mulhi(lo,644); /* -390...322 */
   a0 += s0; /* -390...577 */
   a0 += (a0>>15)&644; /* 0...643 */
-  a1 = (ri<<6)+((s0-a0)>>2);
+  a1 = (int16) ((ri<<6)+((s0-a0)>>2));
   a1 = mullo(a1,-7327);
 
   /* invalid inputs might need reduction mod 4591 */
@@ -254,7 +254,7 @@
     a0 = mulhi(ri,-272)-mulhi(lo,644); /* -390...322 */
     a0 += s0; /* -390...577 */
     a0 += (a0>>15)&644; /* 0...643 */
-    a1 = (ri<<6)+((s0-a0)>>2);
+    a1 = (int16) ((ri<<6)+((s0-a0)>>2));
     a1 = mullo(a1,-7327);
 
     /* invalid inputs might need reduction mod 644 */
@@ -277,7 +277,7 @@
     a0 -= 406; /* -609..>71 */
     a0 += (a0>>15)&406; /* -203...405 */
     a0 += (a0>>15)&406; /* 0...405 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,25827);
 
     /* invalid inputs might need reduction mod 406 */
@@ -300,7 +300,7 @@
     a0 -= 322; /* -483..>106 */
     a0 += (a0>>15)&322; /* -161...321 */
     a0 += (a0>>15)&322; /* 0...321 */
-    a1 = (ri<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<7)+((s0-a0)>>1));
     a1 = mullo(a1,-7327);
 
     /* invalid inputs might need reduction mod 322 */
@@ -325,7 +325,7 @@
     a0 = mulhi(a0,1702)-mulhi(lo,4591); /* -2356...2372 */
     a0 += s0; /* -2356...2627 */
     a0 += (a0>>15)&4591; /* 0...4590 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,15631);
 
     /* invalid inputs might need reduction mod 4591 */
diff -ru --no-dereference supercop-20200826/crypto_decode/761x4591/portable/decode.c supercop-20200826-patched/crypto_decode/761x4591/portable/decode.c
