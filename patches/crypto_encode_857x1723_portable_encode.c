--- supercop-20200826/crypto_encode/857x1723/portable/encode.c	2020-08-31 19:56:55.595748342 -0400
+++ supercop-20200826-patched/crypto_encode/857x1723/portable/encode.c	2020-08-31 20:09:19.807727175 -0400
@@ -18,21 +18,21 @@
   uint32 r2;
   
   for (i = 0;i < 428;++i) {
-    r0 = (((R0[2*i]+2583)&16383)*10923)>>15;
-    r1 = (((R0[2*i+1]+2583)&16383)*10923)>>15;
+    r0 = (uint16) ((((R0[2*i]+2583)&16383)*10923)>>15);
+    r1 = (uint16) ((((R0[2*i+1]+2583)&16383)*10923)>>15);
     r2 = r0+r1*(uint32)1723;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
-  R[428] = (((R0[856]+2583)&16383)*10923)>>15;
+  R[428] = (uint16) ((((R0[856]+2583)&16383)*10923)>>15);
   
   for (i = 0;i < 214;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)11597;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[214] = R[428];
   
@@ -40,9 +40,9 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)2053;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[107] = R[214];
   
@@ -50,34 +50,34 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)65;
-    R[i] = r2;
+    R[i] = (uint16) r2;
   }
   r0 = R[106];
   r1 = R[107];
   r2 = r0+r1*(uint32)65;
-  *out++ = r2; r2 >>= 8;
-  R[53] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[53] = (uint16) r2;
   
   for (i = 0;i < 26;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)4225;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[52];
   r1 = R[53];
   r2 = r0+r1*(uint32)4225;
-  *out++ = r2; r2 >>= 8;
-  R[26] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[26] = (uint16) r2;
   
   for (i = 0;i < 13;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)273;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[13] = R[26];
   
@@ -85,16 +85,16 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)292;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   for (i = 0;i < 3;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)334;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[3] = R[6];
   
@@ -102,17 +102,17 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)436;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)743;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857x1723round/avx/encode.c supercop-20200826-patched/crypto_encode/857x1723round/avx/encode.c
