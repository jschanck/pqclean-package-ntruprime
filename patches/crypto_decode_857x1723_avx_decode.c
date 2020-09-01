--- supercop-20200826/crypto_decode/857x1723/avx/decode.c	2020-08-31 20:12:38.925042358 -0400
+++ supercop-20200826-patched/crypto_decode/857x1723/avx/decode.c	2020-08-31 20:09:19.771726919 -0400
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
 
@@ -88,13 +88,13 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R10[0];
+  a0 = R10[0];
   a0 = mulhi(a0,276)-mulhi(mullo(a0,-22580),743); /* -372...440 */
   a0 += s[2*i+1]; /* -372...695 */
   a0 = mulhi(a0,276)-mulhi(mullo(a0,-22580),743); /* -374...374 */
   a0 += s[2*i+0]; /* -374...629 */
   a0 += (a0>>15)&743; /* 0...742 */
-  a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+  a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
   a1 = mullo(a1,-3881);
 
   /* invalid inputs might need reduction mod 14044 */
@@ -115,7 +115,7 @@
   a0 -= 436; /* -670..>37 */
   a0 += (a0>>15)&436; /* -234...435 */
   a0 += (a0>>15)&436; /* 0...435 */
-  a1 = (a2<<6)+((s[i]-a0)>>2);
+  a1 = (int16) ((a2<<6)+((s[i]-a0)>>2));
   a1 = mullo(a1,2405);
 
   /* invalid inputs might need reduction mod 8246 */
@@ -132,7 +132,7 @@
     a0 -= 436; /* -670..>37 */
     a0 += (a0>>15)&436; /* -234...435 */
     a0 += (a0>>15)&436; /* 0...435 */
-    a1 = (a2<<6)+((s[i]-a0)>>2);
+    a1 = (int16) ((a2<<6)+((s[i]-a0)>>2));
     a1 = mullo(a1,2405);
 
     /* invalid inputs might need reduction mod 436 */
@@ -154,7 +154,7 @@
     a0 -= 334; /* -501..>103 */
     a0 += (a0>>15)&334; /* -167...333 */
     a0 += (a0>>15)&334; /* 0...333 */
-    a1 = (a2<<7)+((s[i]-a0)>>1);
+    a1 = (int16) ((a2<<7)+((s[i]-a0)>>1));
     a1 = mullo(a1,-22761);
 
     /* invalid inputs might need reduction mod 334 */
@@ -175,7 +175,7 @@
   a0 -= 292; /* -438..>125 */
   a0 += (a0>>15)&292; /* -146...291 */
   a0 += (a0>>15)&292; /* 0...291 */
-  a1 = (a2<<6)+((s[i]-a0)>>2);
+  a1 = (int16) ((a2<<6)+((s[i]-a0)>>2));
   a1 = mullo(a1,-3591);
 
   /* invalid inputs might need reduction mod 7229 */
@@ -192,7 +192,7 @@
     a0 -= 292; /* -438..>125 */
     a0 += (a0>>15)&292; /* -146...291 */
     a0 += (a0>>15)&292; /* 0...291 */
-    a1 = (a2<<6)+((s[i]-a0)>>2);
+    a1 = (int16) ((a2<<6)+((s[i]-a0)>>2));
     a1 = mullo(a1,-3591);
 
     /* invalid inputs might need reduction mod 292 */
@@ -214,7 +214,7 @@
     a0 -= 273; /* -410..>118 */
     a0 += (a0>>15)&273; /* -137...272 */
     a0 += (a0>>15)&273; /* 0...272 */
-    a1 = (a2<<8)+s[i]-a0;
+    a1 = (int16) ((a2<<8)+s[i]-a0);
     a1 = mullo(a1,4081);
 
     /* invalid inputs might need reduction mod 273 */
@@ -233,7 +233,7 @@
   a0 = mulhi(a0,-259)-mulhi(mullo(a0,-3971),4225); /* -2178...2112 */
   a0 += s[1*i+0]; /* -2178...2367 */
   a0 += (a0>>15)&4225; /* 0...4224 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,12161);
 
   /* invalid inputs might need reduction mod 438 */
@@ -245,7 +245,7 @@
   s -= 52;
   i = 10;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R5[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -285,7 +285,7 @@
   a0 += s[1*i+0]; /* -33...287 */
   a0 = mulhi(a0,16)-mulhi(mullo(a0,-1008),65); /* -33...32 */
   a0 += (a0>>15)&65; /* 0...64 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,4033);
 
   /* invalid inputs might need reduction mod 1723 */
@@ -328,7 +328,7 @@
   s -= 214;
   i = 91;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R3[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R3[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -365,7 +365,7 @@
   s -= 428;
   i = 198;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -398,7 +398,7 @@
   
   /* R1 ------> R0: reconstruct mod 857*[1723] */
   
-  R0[856] = 3*R1[428]-2583;
+  R0[856] = (int16) (3*R1[428]-2583);
   s -= 428;
   i = 412;
   for (;;) {
diff -ru --no-dereference supercop-20200826/crypto_decode/857x1723/int16/decode.c supercop-20200826-patched/crypto_decode/857x1723/int16/decode.c
