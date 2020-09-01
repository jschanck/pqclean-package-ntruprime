--- supercop-20200826/crypto_decode/857x5167/avx/decode.c	2020-08-31 20:12:38.929042383 -0400
+++ supercop-20200826-patched/crypto_decode/857x5167/avx/decode.c	2020-08-31 20:09:19.775726948 -0400
@@ -14,7 +14,7 @@
 
 static inline int16 mulhi(int16 x,int16 y)
 {
-  return (x*(int32)y)>>16;
+  return (int16) ((x*(int32)y)>>16);
 }
 
 static inline __m256i add(__m256i x,__m256i y)
@@ -60,7 +60,7 @@
 static inline __m256i ifgesubconst(__m256i x,int16 y)
 {
   __m256i y16 = _mm256_set1_epi16(y);
-  __m256i top16 = _mm256_set1_epi16(y-1);
+  __m256i top16 = _mm256_set1_epi16((int16)(y-1));
   return sub(x,_mm256_cmpgt_epi16(x,top16) & y16);
 }
 
@@ -93,7 +93,7 @@
   a0 = mulhi(a0,-1248)-mulhi(mullo(a0,-3064),5476); /* -3050...2738 */
   a0 += s[1*i+0]; /* -3050...2993 */
   a0 += (a0>>15)&5476; /* 0...5475 */
-  a1 = (a2<<6)+((s[i]-a0)>>2);
+  a1 = (int16) ((a2<<6)+((s[i]-a0)>>2));
   a1 = mullo(a1,-3351);
 
   /* invalid inputs might need reduction mod 291 */
@@ -113,7 +113,7 @@
   a0 += s[1*i+0]; /* -37...294 */
   a0 = mulhi(a0,-28)-mulhi(mullo(a0,-886),74); /* -38...37 */
   a0 += (a0>>15)&74; /* 0...73 */
-  a1 = (a2<<7)+((s[i]-a0)>>1);
+  a1 = (int16) ((a2<<7)+((s[i]-a0)>>1));
   a1 = mullo(a1,7085);
 
   /* invalid inputs might need reduction mod 1004 */
@@ -127,7 +127,7 @@
     a2 = a0 = R9[i];
     a0 = mulhi(a0,-28)-mulhi(mullo(a0,-886),74); /* -44...37 */
     a0 += (a0>>15)&74; /* 0...73 */
-    a1 = (a2-a0)>>1;
+    a1 = (int16) (a2-a0)>>1;
     a1 = mullo(a1,7085);
 
     /* invalid inputs might need reduction mod 74 */
@@ -149,7 +149,7 @@
     a0 = mulhi(a0,-302)-mulhi(mullo(a0,-7647),2194); /* -1104...1102 */
     a0 += s[2*i+0]; /* -1104...1357 */
     a0 += (a0>>15)&2194; /* 0...2193 */
-    a1 = (a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1);
+    a1 = (int16) ((a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1));
     a1 = mullo(a1,11769);
 
     /* invalid inputs might need reduction mod 2194 */
@@ -164,13 +164,13 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R7[6];
+  a0 = R7[6];
   a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -5996...6447 */
   a0 += s[2*i+1]; /* -5996...6702 */
   a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -6161...6180 */
   a0 += s[2*i+0]; /* -6161...6435 */
   a0 += (a0>>15)&11991; /* 0...11990 */
-  a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+  a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
   a1 = mullo(a1,-23321);
 
   /* invalid inputs might need reduction mod 5483 */
@@ -181,13 +181,13 @@
   R6[13] = a1;
   s -= 12;
   for (i = 5;i >= 0;--i) {
-    a2 = a0 = R7[i];
+    a0 = R7[i];
     a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -5996...6447 */
     a0 += s[2*i+1]; /* -5996...6702 */
     a0 = mulhi(a0,1807)-mulhi(mullo(a0,-1399),11991); /* -6161...6180 */
     a0 += s[2*i+0]; /* -6161...6435 */
     a0 += (a0>>15)&11991; /* 0...11990 */
-    a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+    a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
     a1 = mullo(a1,-23321);
 
     /* invalid inputs might need reduction mod 11991 */
@@ -207,7 +207,7 @@
     a0 = mulhi(a0,64)-mulhi(mullo(a0,-9576),1752); /* -876...892 */
     a0 += s[1*i+0]; /* -876...1147 */
     a0 += (a0>>15)&1752; /* 0...1751 */
-    a1 = (a2<<5)+((s[i]-a0)>>3);
+    a1 = (int16) ((a2<<5)+((s[i]-a0)>>3));
     a1 = mullo(a1,-1197);
 
     /* invalid inputs might need reduction mod 1752 */
@@ -226,7 +226,7 @@
   a0 = mulhi(a0,658)-mulhi(mullo(a0,-1566),10713); /* -5357...5521 */
   a0 += s[1*i+0]; /* -5357...5776 */
   a0 += (a0>>15)&10713; /* 0...10712 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,-14743);
 
   /* invalid inputs might need reduction mod 131 */
@@ -238,7 +238,7 @@
   s -= 52;
   i = 10;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -279,7 +279,7 @@
   a0 = mulhi(a0,280)-mulhi(mullo(a0,-10131),1656); /* -832...832 */
   a0 += s[2*i+0]; /* -832...1087 */
   a0 += (a0>>15)&1656; /* 0...1655 */
-  a1 = (a2<<13)+(s[2*i+1]<<5)+((s[2*i]-a0)>>3);
+  a1 = (int16) ((a2<<13)+(s[2*i+1]<<5)+((s[2*i]-a0)>>3));
   a1 = mullo(a1,1583);
 
   /* invalid inputs might need reduction mod 5167 */
@@ -394,7 +394,7 @@
   s -= 856;
   i = 412;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/857x5167/int16/decode.c supercop-20200826-patched/crypto_decode/857x5167/int16/decode.c
