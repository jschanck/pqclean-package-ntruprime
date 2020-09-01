--- supercop-20200826/crypto_encode/653x4621/portable/encode.c	2020-08-31 20:12:38.957042556 -0400
+++ supercop-20200826-patched/crypto_encode/653x4621/portable/encode.c	2020-08-31 20:09:19.791727061 -0400
@@ -21,9 +21,9 @@
     r0 = (R0[2*i]+2310)&16383;
     r1 = (R0[2*i+1]+2310)&16383;
     r2 = r0+r1*(uint32)4621;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[326] = (R0[652]+2310)&16383;
   
@@ -31,8 +31,8 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)326;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[163] = R[326];
   
@@ -40,30 +40,30 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)416;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   for (i = 0;i < 40;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)676;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[80];
   r1 = R[81];
   r2 = r0+r1*(uint32)676;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[40] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[40] = (uint16) r2;
   
   for (i = 0;i < 20;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1786;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[20] = R[40];
   
@@ -71,9 +71,9 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)12461;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[10] = R[20];
   
@@ -81,9 +81,9 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)2370;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[5] = R[10];
   
@@ -91,24 +91,24 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)86;
-    R[i] = r2;
+    R[i] = (uint16) r2;
   }
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)7396;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   R[1] = R[2];
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)835;
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
diff -ru --no-dereference supercop-20200826/crypto_encode/653xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/653xfreeze3/ref/encode.c
