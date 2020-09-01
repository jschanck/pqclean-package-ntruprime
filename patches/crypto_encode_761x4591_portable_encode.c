--- supercop-20200826/crypto_encode/761x4591/portable/encode.c	2020-08-31 20:12:38.973042653 -0400
+++ supercop-20200826-patched/crypto_encode/761x4591/portable/encode.c	2020-08-31 20:09:19.803727146 -0400
@@ -21,9 +21,9 @@
     r0 = (R0[2*i]+2295)&16383;
     r1 = (R0[2*i+1]+2295)&16383;
     r2 = r0+r1*(uint32)4591;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[380] = (R0[760]+2295)&16383;
   
@@ -31,8 +31,8 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)322;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[190] = R[380];
   
@@ -40,8 +40,8 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)406;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[95] = R[190];
   
@@ -49,81 +49,81 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)644;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   for (i = 0;i < 23;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1621;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[46];
   r1 = R[47];
   r2 = r0+r1*(uint32)1621;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[23] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[23] = (uint16) r2;
   
   for (i = 0;i < 11;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)10265;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[22];
   r1 = R[23];
   r2 = r0+r1*(uint32)10265;
-  *out++ = r2; r2 >>= 8;
-  R[11] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[11] = (uint16) r2;
   
   for (i = 0;i < 5;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1608;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[10];
   r1 = R[11];
   r2 = r0+r1*(uint32)1608;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[5] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[5] = (uint16) r2;
   
   for (i = 0;i < 2;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)10101;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[4];
   r1 = R[5];
   r2 = r0+r1*(uint32)10101;
-  *out++ = r2; r2 >>= 8;
-  R[2] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[2] = (uint16) r2;
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)1557;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   R[1] = R[2];
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)9470;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/761xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/761xfreeze3/ref/encode.c
