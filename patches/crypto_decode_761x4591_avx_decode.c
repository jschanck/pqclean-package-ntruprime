--- supercop-20200826/crypto_decode/761x4591/avx/decode.c	2020-08-31 20:12:38.917042308 -0400
+++ supercop-20200826-patched/crypto_decode/761x4591/avx/decode.c	2020-08-31 20:09:19.767726890 -0400
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
 
@@ -95,7 +95,7 @@
   a0 = mulhi(a0,-3624)-mulhi(mullo(a0,-1772),9470); /* -5011...5046 */
   a0 += s[2*i+0]; /* -5011...5301 */
   a0 += (a0>>15)&9470; /* 0...9469 */
-  a1 = (a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1);
+  a1 = (int16) ((a2<<15)+(s[2*i+1]<<7)+((s[2*i]-a0)>>1));
   a1 = mullo(a1,-21121);
 
   /* invalid inputs might need reduction mod 11127 */
@@ -115,7 +115,7 @@
     a0 = mulhi(a0,541)-mulhi(mullo(a0,-10775),1557); /* -779...913 */
     a0 += s[1*i+0]; /* -779...1168 */
     a0 += (a0>>15)&1557; /* 0...1556 */
-    a1 = (a2<<8)+s[i]-a0;
+    a1 = (int16) ((a2<<8)+s[i]-a0);
     a1 = mullo(a1,-26307);
 
     /* invalid inputs might need reduction mod 1557 */
@@ -134,7 +134,7 @@
   a0 = mulhi(a0,-545)-mulhi(mullo(a0,-1661),10101); /* -5187...5050 */
   a0 += s[1*i+0]; /* -5187...5305 */
   a0 += (a0>>15)&10101; /* 0...10100 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,12509);
 
   /* invalid inputs might need reduction mod 282 */
@@ -145,13 +145,13 @@
   R7[5] = a1;
   s -= 4;
   for (i = 1;i >= 0;--i) {
-    a2 = a0 = R8[i];
+    a0 = R8[i];
     a0 = mulhi(a0,-545)-mulhi(mullo(a0,-1661),10101); /* -5187...5050 */
     a0 += s[2*i+1]; /* -5187...5305 */
     a0 = mulhi(a0,-545)-mulhi(mullo(a0,-1661),10101); /* -5095...5093 */
     a0 += s[2*i+0]; /* -5095...5348 */
     a0 += (a0>>15)&10101; /* 0...10100 */
-    a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+    a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
     a1 = mullo(a1,12509);
 
     /* invalid inputs might need reduction mod 10101 */
@@ -172,7 +172,7 @@
   a0 = mulhi(a0,-656)-mulhi(mullo(a0,-10434),1608); /* -815...813 */
   a0 += s[2*i+0]; /* -815...1068 */
   a0 += (a0>>15)&1608; /* 0...1607 */
-  a1 = (a2<<13)+(s[2*i+1]<<5)+((s[2*i]-a0)>>3);
+  a1 = (int16) ((a2<<13)+(s[2*i+1]<<5)+((s[2*i]-a0)>>3));
   a1 = mullo(a1,6521);
 
   /* invalid inputs might need reduction mod 11468 */
@@ -187,7 +187,7 @@
     a0 = mulhi(a0,-656)-mulhi(mullo(a0,-10434),1608); /* -968...804 */
     a0 += s[1*i+0]; /* -968...1059 */
     a0 += (a0>>15)&1608; /* 0...1607 */
-    a1 = (a2<<5)+((s[i]-a0)>>3);
+    a1 = (int16) ((a2<<5)+((s[i]-a0)>>3));
     a1 = mullo(a1,6521);
 
     /* invalid inputs might need reduction mod 1608 */
@@ -206,7 +206,7 @@
   a0 = mulhi(a0,4206)-mulhi(mullo(a0,-1634),10265); /* -5133...6184 */
   a0 += s[1*i+0]; /* -5133...6439 */
   a0 += (a0>>15)&10265; /* 0...10264 */
-  a1 = (a2<<8)+s[i]-a0;
+  a1 = (int16) ((a2<<8)+s[i]-a0);
   a1 = mullo(a1,-19415);
 
   /* invalid inputs might need reduction mod 286 */
@@ -217,13 +217,13 @@
   R5[23] = a1;
   s -= 22;
   for (i = 10;i >= 0;--i) {
-    a2 = a0 = R6[i];
+    a0 = R6[i];
     a0 = mulhi(a0,4206)-mulhi(mullo(a0,-1634),10265); /* -5133...6184 */
     a0 += s[2*i+1]; /* -5133...6439 */
     a0 = mulhi(a0,4206)-mulhi(mullo(a0,-1634),10265); /* -5462...5545 */
     a0 += s[2*i+0]; /* -5462...5800 */
     a0 += (a0>>15)&10265; /* 0...10264 */
-    a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+    a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
     a1 = mullo(a1,-19415);
 
     /* invalid inputs might need reduction mod 10265 */
@@ -238,13 +238,13 @@
   
   i = 0;
   s -= 2;
-  a2 = a0 = R5[23];
+  a0 = R5[23];
   a0 = mulhi(a0,-134)-mulhi(mullo(a0,-10350),1621); /* -844...810 */
   a0 += s[2*i+1]; /* -844...1065 */
   a0 = mulhi(a0,-134)-mulhi(mullo(a0,-10350),1621); /* -813...812 */
   a0 += s[2*i+0]; /* -813...1067 */
   a0 += (a0>>15)&1621; /* 0...1620 */
-  a1 = (s[2*i+1]<<8)+s[2*i]-a0;
+  a1 = (int16) ((s[2*i+1]<<8)+s[2*i]-a0);
   a1 = mullo(a1,-14595);
 
   /* invalid inputs might need reduction mod 11550 */
@@ -291,7 +291,7 @@
   a0 = mulhi(a0,-272)-mulhi(mullo(a0,-26052),644); /* -390...322 */
   a0 += s[1*i+0]; /* -390...577 */
   a0 += (a0>>15)&644; /* 0...643 */
-  a1 = (a2<<6)+((s[i]-a0)>>2);
+  a1 = (int16) ((a2<<6)+((s[i]-a0)>>2));
   a1 = mullo(a1,-7327);
 
   /* invalid inputs might need reduction mod 4591 */
@@ -406,7 +406,7 @@
   s -= 760;
   i = 364;
   for (;;) {
-    A2 = A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
+    A0 = _mm256_loadu_si256((__m256i *) &R1[i]);
     S0 = _mm256_loadu_si256((__m256i *) (s+2*i));
     S1 = _mm256_srli_epi16(S0,8);
     S0 &= _mm256_set1_epi16(255);
diff -ru --no-dereference supercop-20200826/crypto_decode/761x4591/int16/decode.c supercop-20200826-patched/crypto_decode/761x4591/int16/decode.c
