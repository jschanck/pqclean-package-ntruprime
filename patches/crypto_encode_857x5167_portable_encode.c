--- supercop-20200826/crypto_encode/857x5167/portable/encode.c	2020-08-31 20:12:38.989042753 -0400
+++ supercop-20200826-patched/crypto_encode/857x5167/portable/encode.c	2020-08-31 20:09:19.811727204 -0400
@@ -21,9 +21,9 @@
     r0 = (R0[2*i]+2583)&16383;
     r1 = (R0[2*i+1]+2583)&16383;
     r2 = r0+r1*(uint32)5167;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[428] = (R0[856]+2583)&16383;
   
@@ -31,8 +31,8 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)408;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[214] = R[428];
   
@@ -40,8 +40,8 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)651;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[107] = R[214];
   
@@ -49,36 +49,36 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1656;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[106];
   r1 = R[107];
   r2 = r0+r1*(uint32)1656;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[53] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[53] = (uint16) r2;
   
   for (i = 0;i < 26;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)10713;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[52];
   r1 = R[53];
   r2 = r0+r1*(uint32)10713;
-  *out++ = r2; r2 >>= 8;
-  R[26] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[26] = (uint16) r2;
   
   for (i = 0;i < 13;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1752;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[13] = R[26];
   
@@ -86,38 +86,38 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)11991;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   for (i = 0;i < 3;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)2194;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[3] = R[6];
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)74;
-  R[0] = r2;
+  R[0] = (uint16) r2;
   r0 = R[2];
   r1 = R[3];
   r2 = r0+r1*(uint32)74;
-  *out++ = r2; r2 >>= 8;
-  R[1] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[1] = (uint16) r2;
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)5476;
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
diff -ru --no-dereference supercop-20200826/crypto_encode/857xfreeze3/ref/encode.c supercop-20200826-patched/crypto_encode/857xfreeze3/ref/encode.c
