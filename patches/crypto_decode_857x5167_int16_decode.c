--- supercop-20200826/crypto_decode/857x5167/int16/decode.c	2020-08-31 20:12:38.933042407 -0400
+++ supercop-20200826-patched/crypto_decode/857x5167/int16/decode.c	2020-08-31 20:09:19.775726948 -0400
@@ -39,7 +39,7 @@
   a0 = mulhi(ri,-1248)-mulhi(lo,5476); /* -3050...2738 */
   a0 += s0; /* -3050...2993 */
   a0 += (a0>>15)&5476; /* 0...5475 */
-  a1 = (ri<<6)+((s0-a0)>>2);
+  a1 = (int16) ((ri<<6)+((s0-a0)>>2));
   a1 = mullo(a1,-3351);
 
   /* invalid inputs might need reduction mod 291 */
@@ -59,7 +59,7 @@
   lo = mullo(a0,-886);
   a0 = mulhi(a0,-28)-mulhi(lo,74); /* -38...37 */
   a0 += (a0>>15)&74; /* 0...73 */
-  a1 = (ri<<7)+((s0-a0)>>1);
+  a1 = (int16) ((ri<<7)+((s0-a0)>>1));
   a1 = mullo(a1,7085);
 
   /* invalid inputs might need reduction mod 1004 */
@@ -99,7 +99,7 @@
     a0 = mulhi(a0,-302)-mulhi(lo,2194); /* -1104...1102 */
     a0 += s0; /* -1104...1357 */
     a0 += (a0>>15)&2194; /* 0...2193 */
-    a1 = (ri<<15)+(s1<<7)+((s0-a0)>>1);
+    a1 = (int16) ((ri<<15)+(s1<<7)+((s0-a0)>>1));
     a1 = mullo(a1,11769);
 
     /* invalid inputs might need reduction mod 2194 */
@@ -122,7 +122,7 @@
   a0 = mulhi(a0,1807)-mulhi(lo,11991); /* -6161...6180 */
   a0 += s0; /* -6161...6435 */
   a0 += (a0>>15)&11991; /* 0...11990 */
-  a1 = (s1<<8)+s0-a0;
+  a1 = (int16) ((s1<<8)+s0-a0);
   a1 = mullo(a1,-23321);
 
   /* invalid inputs might need reduction mod 5483 */
@@ -142,7 +142,7 @@
     a0 = mulhi(a0,1807)-mulhi(lo,11991); /* -6161...6180 */
     a0 += s0; /* -6161...6435 */
     a0 += (a0>>15)&11991; /* 0...11990 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-23321);
 
     /* invalid inputs might need reduction mod 11991 */
@@ -163,7 +163,7 @@
     a0 = mulhi(ri,64)-mulhi(lo,1752); /* -876...892 */
     a0 += s0; /* -876...1147 */
     a0 += (a0>>15)&1752; /* 0...1751 */
-    a1 = (ri<<5)+((s0-a0)>>3);
+    a1 = (int16) ((ri<<5)+((s0-a0)>>3));
     a1 = mullo(a1,-1197);
 
     /* invalid inputs might need reduction mod 1752 */
@@ -182,7 +182,7 @@
   a0 = mulhi(ri,658)-mulhi(lo,10713); /* -5357...5521 */
   a0 += s0; /* -5357...5776 */
   a0 += (a0>>15)&10713; /* 0...10712 */
-  a1 = (ri<<8)+s0-a0;
+  a1 = (int16) ((ri<<8)+s0-a0);
   a1 = mullo(a1,-14743);
 
   /* invalid inputs might need reduction mod 131 */
@@ -202,7 +202,7 @@
     a0 = mulhi(a0,658)-mulhi(lo,10713); /* -5411...5414 */
     a0 += s0; /* -5411...5669 */
     a0 += (a0>>15)&10713; /* 0...10712 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-14743);
 
     /* invalid inputs might need reduction mod 10713 */
@@ -225,7 +225,7 @@
   a0 = mulhi(a0,280)-mulhi(lo,1656); /* -832...832 */
   a0 += s0; /* -832...1087 */
   a0 += (a0>>15)&1656; /* 0...1655 */
-  a1 = (ri<<13)+(s1<<5)+((s0-a0)>>3);
+  a1 = (int16) ((ri<<13)+(s1<<5)+((s0-a0)>>3));
   a1 = mullo(a1,1583);
 
   /* invalid inputs might need reduction mod 5167 */
@@ -241,7 +241,7 @@
     a0 = mulhi(ri,280)-mulhi(lo,1656); /* -828...898 */
     a0 += s0; /* -828...1153 */
     a0 += (a0>>15)&1656; /* 0...1655 */
-    a1 = (ri<<5)+((s0-a0)>>3);
+    a1 = (int16) ((ri<<5)+((s0-a0)>>3));
     a1 = mullo(a1,1583);
 
     /* invalid inputs might need reduction mod 1656 */
@@ -264,7 +264,7 @@
     a0 -= 651; /* -977..>3 */
     a0 += (a0>>15)&651; /* -326...650 */
     a0 += (a0>>15)&651; /* 0...650 */
-    a1 = (ri<<8)+s0-a0;
+    a1 = (int16) ((ri<<8)+s0-a0);
     a1 = mullo(a1,-10973);
 
     /* invalid inputs might need reduction mod 651 */
@@ -287,7 +287,7 @@
     a0 -= 408; /* -650..>51 */
     a0 += (a0>>15)&408; /* -242...407 */
     a0 += (a0>>15)&408; /* 0...407 */
-    a1 = (ri<<5)+((s0-a0)>>3);
+    a1 = (int16) ((ri<<5)+((s0-a0)>>3));
     a1 = mullo(a1,-1285);
 
     /* invalid inputs might need reduction mod 408 */
@@ -312,7 +312,7 @@
     a0 = mulhi(a0,-33)-mulhi(lo,5167); /* -2585...2584 */
     a0 += s0; /* -2585...2839 */
     a0 += (a0>>15)&5167; /* 0...5166 */
-    a1 = (s1<<8)+s0-a0;
+    a1 = (int16) ((s1<<8)+s0-a0);
     a1 = mullo(a1,-19761);
 
     /* invalid inputs might need reduction mod 5167 */
diff -ru --no-dereference supercop-20200826/crypto_decode/857x5167/portable/decode.c supercop-20200826-patched/crypto_decode/857x5167/portable/decode.c
