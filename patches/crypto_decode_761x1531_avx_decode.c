--- supercop-20200826/crypto_decode/761x1531/avx/decode.c	2020-08-31 20:12:38.913042284 -0400
+++ supercop-20200826-patched/crypto_decode/761x1531/avx/decode.c	2020-08-31 20:09:19.763726863 -0400
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
   a0 = mulhi(a0,60)-mulhi(mullo(a0,-28292),593); /* -297...311 */
   a0 += s[1*i+0]; /* -297...566 */
   a0 += (a0>>15)&593; /* 0...592 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,-31055);
 
   /* invalid inputs might need reduction mod 1500 */
@@ -115,7 +115,7 @@
     a0 = mulhi(a0,672)-mulhi(mullo(a0,-2692),6232); /* -3148...3152 */
     a0 += s[2*i+0]; /* -3148...3407 */
     a0 += (a0>>15)&6232; /* 0...6231 */
-    a1 = (a2<<13)+(s[2*i+1]<<5)+((s[2*i]-a0)>>3);
+    a1 = (int16) ((a2<<13)+(s[2*i+1]<<5)+((s[2*i]-a0)>>3));
     a1 = mullo(a1,12451);
 
     /* invalid inputs might need reduction mod 6232 */
@@ -134,7 +134,7 @@
   a0 = mulhi(a0,-476)-mulhi(mullo(a0,-13284),1263); /* -751...631 */
   a0 += s[1*i+0]; /* -751...886 */
   a0 += (a0>>15)&1263; /* 0...1262 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,-22001);
 
   /* invalid inputs might need reduction mod 304 */
@@ -149,7 +149,7 @@
     a0 = mulhi(a0,-476)-mulhi(mullo(a0,-13284),1263); /* -751...631 */
     a0 += s[1*i+0]; /* -751...886 */
     a0 += (a0>>15)&1263; /* 0...1262 */
-    a1 = (a2<<8)+s[i]-a0;
+    a1 = (int16) ((a2<<8)+s[i]-a0);
     a1 = mullo(a1,-22001);
 
     /* invalid inputs might need reduction mod 1263 */
@@ -164,13 +164,13 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R7[5];
+  a0 = R7[5];
   a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4549...5135 */
   a0 += s[2*i+1]; /* -4549...5390 */
   a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4712...4741 */
   a0 += s[2*i+0]; /* -4712...4996 */
   a0 += (a0>>15)&9097; /* 0...9096 */
-  a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+  a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
   a1 = mullo(a1,17081);
 
   /* invalid inputs might need reduction mod 2188 */
@@ -181,13 +181,13 @@
   R6[11] = a1;
   s -= 10;
   for (i = 4;i >= 0;--i) {
-    a2 = a0 = R7[i];
+    a0 = R7[i];
     a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4549...5135 */
     a0 += s[2*i+1]; /* -4549...5390 */
     a0 = mulhi(a0,2348)-mulhi(mullo(a0,-1844),9097); /* -4712...4741 */
     a0 += s[2*i+0]; /* -4712...4996 */
     a0 += (a0>>15)&9097; /* 0...9096 */
-    a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+    a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
     a1 = mullo(a1,17081);
 
     /* invalid inputs might need reduction mod 9097 */
@@ -206,7 +206,7 @@
   a0 = mulhi(a0,372)-mulhi(mullo(a0,-10994),1526); /* -763...856 */
   a0 += s[1*i+0]; /* -763...1111 */
   a0 += (a0>>15)&1526; /* 0...1525 */
-  a1 = (a2<<7)+((s[i]-a0)>>1);
+  a1 = (int16) ((a2<<7)+((s[i]-a0)>>1));
   a1 = mullo(a1,-18381);
 
   /* invalid inputs might need reduction mod 367 */
@@ -221,7 +221,7 @@
     a0 = mulhi(a0,372)-mulhi(mullo(a0,-10994),1526); /* -763...856 */
     a0 += s[1*i+0]; /* -763...1111 */
     a0 += (a0>>15)&1526; /* 0...1525 */
-    a1 = (a2<<7)+((s[i]-a0)>>1);
+    a1 = (int16) ((a2<<7)+((s[i]-a0)>>1));
     a1 = mullo(a1,-18381);
 
     /* invalid inputs might need reduction mod 1526 */
@@ -240,7 +240,7 @@
   a0 = mulhi(a0,-284)-mulhi(mullo(a0,-26844),625); /* -384...312 */
   a0 += s[1*i+0]; /* -384...567 */
   a0 += (a0>>15)&625; /* 0...624 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,32401);
 
   /* invalid inputs might need reduction mod 150 */
@@ -289,7 +289,7 @@
   a0 = mulhi(a0,2816)-mulhi(mullo(a0,-2621),6400); /* -3338...3378 */
   a0 += s[2*i+0]; /* -3338...3633 */
   a0 += (a0>>15)&6400; /* 0...6399 */
-  a1 = (a2<<8)+s[2*i+1]+((s[2*i]-a0)>>8);
+  a1 = (int16) ((a2<<8)+s[2*i+1]+((s[2*i]-a0)>>8));
   a1 = mullo(a1,23593);
 
   /* invalid inputs might need reduction mod 1531 */
@@ -371,7 +371,7 @@
   s -= 380;
   i = 174;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -404,7 +404,7 @@
   
   /* R1 ------> R0: reconstruct mod 761*[1531] */
   
-  R0[760] = 3*R1[380]-2295;
+  R0[760] = (int16) (3*R1[380]-2295);
   s -= 380;
   i = 364;
   for (;;) {
diff -ru --no-dereference supercop-20200826/crypto_decode/761x1531/int16/decode.c supercop-20200826-patched/crypto_decode/761x1531/int16/decode.c
