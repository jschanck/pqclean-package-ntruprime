--- supercop-20200826/crypto_decode/761x1531/portable/decode.c	2020-08-31 20:12:38.917042308 -0400
+++ supercop-20200826-patched/crypto_decode/761x1531/portable/decode.c	2020-08-31 20:09:19.763726863 -0400
@@ -34,7 +34,7 @@
 
   *q = 0;
 
-  qpart = (x*(uint64)v)>>31;
+  qpart = (uint32) ((x*(uint64)v)>>31);
   /* 2^31 qpart <= xv <= 2^31 qpart + 2^31-1 */
   /* 2^31 qpart m <= xvm <= 2^31 qpart m + (2^31-1)m */
   /* 2^31 qpart m <= 2^31 x <= 2^31 qpart m + (2^31-1)m + x(m-1) */
@@ -45,7 +45,7 @@
   x -= qpart*m; *q += qpart;
   /* x <= 49146 */
 
-  qpart = (x*(uint64)v)>>31;
+  qpart = (uint32) ((x*(uint64)v)>>31);
   /* 0 <= newx <= (1-1/2^31)m + x(m-1)/2^31 */
   /* 0 <= newx <= m + 49146(2^14-1)/2^31 */
   /* 0 <= newx <= m + 0.4 */
@@ -59,7 +59,7 @@
   x += mask&(uint32)m; *q += mask;
   /* x < m */
 
-  *r = x;
+  *r = (uint16) x;
 }
 
 static uint16 uint32_mod_uint14(uint32 x,uint16 m)
@@ -83,14 +83,14 @@
   r1 = (r1<<8)|*--s;
   r1 = (r1<<8)|*--s;
   r1 = uint32_mod_uint14(r1,3475); /* needed only for invalid inputs */
-  R10[0] = r1;
+  R10[0] = (uint16) r1;
   
   r2 = R10[0];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,593);
   R9[0] = r0;
   r1 = uint32_mod_uint14(r1,1500); /* needed only for invalid inputs */
-  R9[1] = r1;
+  R9[1] = (uint16) r1;
   
   R8[2] = R9[1];
   r2 = R9[0];
@@ -99,21 +99,21 @@
   uint32_divmod_uint14(&r1,&r0,r2,6232);
   R8[0] = r0;
   r1 = uint32_mod_uint14(r1,6232); /* needed only for invalid inputs */
-  R8[1] = r1;
+  R8[1] = (uint16) r1;
   
   r2 = R8[2];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,1263);
   R7[4] = r0;
   r1 = uint32_mod_uint14(r1,304); /* needed only for invalid inputs */
-  R7[5] = r1;
+  R7[5] = (uint16) r1;
   for (i = 1;i >= 0;--i) {
     r2 = R8[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1263);
     R7[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1263); /* needed only for invalid inputs */
-    R7[2*i+1] = r1;
+    R7[2*i+1] = (uint16) r1;
   }
   
   r2 = R7[5];
@@ -122,7 +122,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,9097);
   R6[10] = r0;
   r1 = uint32_mod_uint14(r1,2188); /* needed only for invalid inputs */
-  R6[11] = r1;
+  R6[11] = (uint16) r1;
   for (i = 4;i >= 0;--i) {
     r2 = R7[i];
     r2 = (r2<<8)|*--s;
@@ -130,7 +130,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,9097);
     R6[2*i] = r0;
     r1 = uint32_mod_uint14(r1,9097); /* needed only for invalid inputs */
-    R6[2*i+1] = r1;
+    R6[2*i+1] = (uint16) r1;
   }
   
   r2 = R6[11];
@@ -138,14 +138,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,1526);
   R5[22] = r0;
   r1 = uint32_mod_uint14(r1,367); /* needed only for invalid inputs */
-  R5[23] = r1;
+  R5[23] = (uint16) r1;
   for (i = 10;i >= 0;--i) {
     r2 = R6[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1526);
     R5[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1526); /* needed only for invalid inputs */
-    R5[2*i+1] = r1;
+    R5[2*i+1] = (uint16) r1;
   }
   
   r2 = R5[23];
@@ -153,14 +153,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,625);
   R4[46] = r0;
   r1 = uint32_mod_uint14(r1,150); /* needed only for invalid inputs */
-  R4[47] = r1;
+  R4[47] = (uint16) r1;
   for (i = 22;i >= 0;--i) {
     r2 = R5[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,625);
     R4[2*i] = r0;
     r1 = uint32_mod_uint14(r1,625); /* needed only for invalid inputs */
-    R4[2*i+1] = r1;
+    R4[2*i+1] = (uint16) r1;
   }
   
   r2 = R4[47];
@@ -169,7 +169,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,6400);
   R3[94] = r0;
   r1 = uint32_mod_uint14(r1,1531); /* needed only for invalid inputs */
-  R3[95] = r1;
+  R3[95] = (uint16) r1;
   for (i = 46;i >= 0;--i) {
     r2 = R4[i];
     r2 = (r2<<8)|*--s;
@@ -177,7 +177,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,6400);
     R3[2*i] = r0;
     r1 = uint32_mod_uint14(r1,6400); /* needed only for invalid inputs */
-    R3[2*i+1] = r1;
+    R3[2*i+1] = (uint16) r1;
   }
   
   R2[190] = R3[95];
@@ -187,7 +187,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,1280);
     R2[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1280); /* needed only for invalid inputs */
-    R2[2*i+1] = r1;
+    R2[2*i+1] = (uint16) r1;
   }
   
   R1[380] = R2[190];
@@ -198,16 +198,16 @@
     uint32_divmod_uint14(&r1,&r0,r2,9157);
     R1[2*i] = r0;
     r1 = uint32_mod_uint14(r1,9157); /* needed only for invalid inputs */
-    R1[2*i+1] = r1;
+    R1[2*i+1] = (uint16) r1;
   }
   
-  R0[760] = 3*R1[380]-2295;
+  R0[760] = (int16) (3*R1[380]-2295);
   for (i = 379;i >= 0;--i) {
     r2 = R1[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1531);
-    R0[2*i] = 3*r0-2295;
+    R0[2*i] = (int16) (3*r0-2295);
     r1 = uint32_mod_uint14(r1,1531); /* needed only for invalid inputs */
-    R0[2*i+1] = 3*r1-2295;
+    R0[2*i+1] = (int16) (3*r1-2295);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/761x4591/avx/decode.c supercop-20200826-patched/crypto_decode/761x4591/avx/decode.c
