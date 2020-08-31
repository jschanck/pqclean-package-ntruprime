--- supercop-20200826/crypto_encode/653x1541/portable/encode.c	2020-08-31 19:56:55.575748009 -0400
+++ supercop-20200826-patched/crypto_encode/653x1541/portable/encode.c	2020-08-31 20:09:19.783727004 -0400
@@ -18,21 +18,21 @@
   uint32 r2;
   
   for (i = 0;i < 326;++i) {
-    r0 = (((R0[2*i]+2310)&16383)*10923)>>15;
-    r1 = (((R0[2*i+1]+2310)&16383)*10923)>>15;
+    r0 = (uint16) ((((R0[2*i]+2310)&16383)*10923)>>15);
+    r1 = (uint16) ((((R0[2*i+1]+2310)&16383)*10923)>>15);
     r2 = r0+r1*(uint32)1541;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
-  R[326] = (((R0[652]+2310)&16383)*10923)>>15;
+  R[326] = (uint16) ((((R0[652]+2310)&16383)*10923)>>15);
   
   for (i = 0;i < 163;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)9277;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[163] = R[326];
   
@@ -40,25 +40,25 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1314;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   for (i = 0;i < 41;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)6745;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   for (i = 0;i < 20;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)695;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[20] = R[40];
   
@@ -66,8 +66,8 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1887;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[10] = R[20];
   
@@ -75,9 +75,9 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)13910;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[5] = R[10];
   
@@ -85,30 +85,30 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)2953;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[4];
   r1 = R[5];
   r2 = r0+r1*(uint32)2953;
-  *out++ = r2; r2 >>= 8;
-  R[2] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[2] = (uint16) r2;
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)134;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   R[1] = R[2];
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)71;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/653x1541round/avx/encode.c supercop-20200826-patched/crypto_encode/653x1541round/avx/encode.c
