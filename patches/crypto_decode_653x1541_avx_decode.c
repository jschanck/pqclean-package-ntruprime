--- supercop-20200826/crypto_decode/653x1541/avx/decode.c	2020-08-31 19:56:55.551747613 -0400
+++ supercop-20200826-patched/crypto_decode/653x1541/avx/decode.c	2020-08-31 20:10:41.740290933 -0400
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
 
@@ -94,7 +94,7 @@
   a0 += s[1*i+0]; /* -39...290 */
   a0 = mulhi(a0,3)-mulhi(mullo(a0,-923),71); /* -36...35 */
   a0 += (a0>>15)&71; /* 0...70 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,-22153);
 
   /* invalid inputs might need reduction mod 9402 */
@@ -115,7 +115,7 @@
     a0 += s[1*i+0]; /* -67...325 */
     a0 = mulhi(a0,10)-mulhi(mullo(a0,-489),134); /* -68...67 */
     a0 += (a0>>15)&134; /* 0...133 */
-    a1 = (a2<<7)+((s[i]-a0)>>1);
+    a1 = (int16) ((a2<<7)+((s[i]-a0)>>1));
     a1 = mullo(a1,19563);
 
     /* invalid inputs might need reduction mod 134 */
@@ -134,7 +134,7 @@
   a0 = mulhi(a0,1223)-mulhi(mullo(a0,-5681),2953); /* -1477...1782 */
   a0 += s[1*i+0]; /* -1477...2037 */
   a0 += (a0>>15)&2953; /* 0...2952 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,-9543);
 
   /* invalid inputs might need reduction mod 815 */
@@ -145,13 +145,13 @@
   R7[5] = a1;
   s -= 4;
   for (i = 1;i >= 0;--i) {
-    a2 = a0 = R8[i];
+    a0 = R8[i];
     a0 = mulhi(a0,1223)-mulhi(mullo(a0,-5681),2953); /* -1477...1782 */
     a0 += s[2*i+1]; /* -1477...2037 */
     a0 = mulhi(a0,1223)-mulhi(mullo(a0,-5681),2953); /* -1505...1514 */
     a0 += s[2*i+0]; /* -1505...1769 */
     a0 += (a0>>15)&2953; /* 0...2952 */
-    a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+    a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
     a1 = mullo(a1,-9543);
 
     /* invalid inputs might need reduction mod 2953 */
@@ -173,7 +173,7 @@
     a0 = mulhi(a0,1756)-mulhi(mullo(a0,-1206),13910); /* -7142...7159 */
     a0 += s[2*i+0]; /* -7142...7414 */
     a0 += (a0>>15)&13910; /* 0...13909 */
-    a1 = (a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1);
+    a1 = (int16) ((a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1));
     a1 = mullo(a1,-13437);
 
     /* invalid inputs might need reduction mod 13910 */
@@ -193,7 +193,7 @@
     a0 = mulhi(a0,-101)-mulhi(mullo(a0,-8891),1887); /* -969...943 */
     a0 += s[1*i+0]; /* -969...1198 */
     a0 += (a0>>15)&1887; /* 0...1886 */
-    a1 = (a2<<8)+s[i]-a0;
+    a1 = (int16) ((a2<<8)+s[i]-a0);
     a1 = mullo(a1,5279);
 
     /* invalid inputs might need reduction mod 1887 */
@@ -241,13 +241,13 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R4[40];
+  a0 = R4[40];
   a0 = mulhi(a0,2401)-mulhi(mullo(a0,-2487),6745); /* -3373...3972 */
   a0 += s[2*i+1]; /* -3373...4227 */
   a0 = mulhi(a0,2401)-mulhi(mullo(a0,-2487),6745); /* -3497...3527 */
   a0 += s[2*i+0]; /* -3497...3782 */
   a0 += (a0>>15)&6745; /* 0...6744 */
-  a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+  a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
   a1 = mullo(a1,-29207);
 
   /* invalid inputs might need reduction mod 7910 */
@@ -259,7 +259,7 @@
   s -= 80;
   i = 24;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R4[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R4[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -298,7 +298,7 @@
   a0 = mulhi(a0,64)-mulhi(mullo(a0,-12768),1314); /* -657...673 */
   a0 += s[1*i+0]; /* -657...928 */
   a0 += (a0>>15)&1314; /* 0...1313 */
-  a1 = (a2<<7)+((s[i]-a0)>>1);
+  a1 = (int16) ((a2<<7)+((s[i]-a0)>>1));
   a1 = mullo(a1,-399);
 
   /* invalid inputs might need reduction mod 1541 */
@@ -343,7 +343,7 @@
   s -= 326;
   i = 147;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R2[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
@@ -376,7 +376,7 @@
   
   /* R1 ------> R0: reconstruct mod 653*[1541] */
   
-  R0[652] = 3*R1[326]-2310;
+  R0[652] = (int16) (3*R1[326]-2310);
   s -= 326;
   i = 310;
   for (;;) {
diff -ru --no-dereference supercop-20200826/crypto_decode/653x1541/int16/decode.c supercop-20200826-patched/crypto_decode/653x1541/int16/decode.c
