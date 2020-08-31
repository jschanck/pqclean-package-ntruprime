--- supercop-20200826/crypto_decode/761x4591/portable/decode.c	2020-08-31 19:56:55.563747812 -0400
+++ supercop-20200826-patched/crypto_decode/761x4591/portable/decode.c	2020-08-31 20:09:19.767726890 -0400
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
@@ -83,7 +83,7 @@
   r1 = (r1<<8)|*--s;
   r1 = (r1<<8)|*--s;
   r1 = uint32_mod_uint14(r1,1608); /* needed only for invalid inputs */
-  R10[0] = r1;
+  R10[0] = (uint16) r1;
   
   r2 = R10[0];
   r2 = (r2<<8)|*--s;
@@ -91,7 +91,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,9470);
   R9[0] = r0;
   r1 = uint32_mod_uint14(r1,11127); /* needed only for invalid inputs */
-  R9[1] = r1;
+  R9[1] = (uint16) r1;
   
   R8[2] = R9[1];
   r2 = R9[0];
@@ -99,14 +99,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,1557);
   R8[0] = r0;
   r1 = uint32_mod_uint14(r1,1557); /* needed only for invalid inputs */
-  R8[1] = r1;
+  R8[1] = (uint16) r1;
   
   r2 = R8[2];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,10101);
   R7[4] = r0;
   r1 = uint32_mod_uint14(r1,282); /* needed only for invalid inputs */
-  R7[5] = r1;
+  R7[5] = (uint16) r1;
   for (i = 1;i >= 0;--i) {
     r2 = R8[i];
     r2 = (r2<<8)|*--s;
@@ -114,7 +114,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,10101);
     R7[2*i] = r0;
     r1 = uint32_mod_uint14(r1,10101); /* needed only for invalid inputs */
-    R7[2*i+1] = r1;
+    R7[2*i+1] = (uint16) r1;
   }
   
   r2 = R7[5];
@@ -123,14 +123,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,1608);
   R6[10] = r0;
   r1 = uint32_mod_uint14(r1,11468); /* needed only for invalid inputs */
-  R6[11] = r1;
+  R6[11] = (uint16) r1;
   for (i = 4;i >= 0;--i) {
     r2 = R7[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1608);
     R6[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1608); /* needed only for invalid inputs */
-    R6[2*i+1] = r1;
+    R6[2*i+1] = (uint16) r1;
   }
   
   r2 = R6[11];
@@ -138,7 +138,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,10265);
   R5[22] = r0;
   r1 = uint32_mod_uint14(r1,286); /* needed only for invalid inputs */
-  R5[23] = r1;
+  R5[23] = (uint16) r1;
   for (i = 10;i >= 0;--i) {
     r2 = R6[i];
     r2 = (r2<<8)|*--s;
@@ -146,7 +146,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,10265);
     R5[2*i] = r0;
     r1 = uint32_mod_uint14(r1,10265); /* needed only for invalid inputs */
-    R5[2*i+1] = r1;
+    R5[2*i+1] = (uint16) r1;
   }
   
   r2 = R5[23];
@@ -155,14 +155,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,1621);
   R4[46] = r0;
   r1 = uint32_mod_uint14(r1,11550); /* needed only for invalid inputs */
-  R4[47] = r1;
+  R4[47] = (uint16) r1;
   for (i = 22;i >= 0;--i) {
     r2 = R5[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1621);
     R4[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1621); /* needed only for invalid inputs */
-    R4[2*i+1] = r1;
+    R4[2*i+1] = (uint16) r1;
   }
   
   r2 = R4[47];
@@ -170,14 +170,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,644);
   R3[94] = r0;
   r1 = uint32_mod_uint14(r1,4591); /* needed only for invalid inputs */
-  R3[95] = r1;
+  R3[95] = (uint16) r1;
   for (i = 46;i >= 0;--i) {
     r2 = R4[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,644);
     R3[2*i] = r0;
     r1 = uint32_mod_uint14(r1,644); /* needed only for invalid inputs */
-    R3[2*i+1] = r1;
+    R3[2*i+1] = (uint16) r1;
   }
   
   R2[190] = R3[95];
@@ -187,7 +187,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,406);
     R2[2*i] = r0;
     r1 = uint32_mod_uint14(r1,406); /* needed only for invalid inputs */
-    R2[2*i+1] = r1;
+    R2[2*i+1] = (uint16) r1;
   }
   
   R1[380] = R2[190];
@@ -197,17 +197,17 @@
     uint32_divmod_uint14(&r1,&r0,r2,322);
     R1[2*i] = r0;
     r1 = uint32_mod_uint14(r1,322); /* needed only for invalid inputs */
-    R1[2*i+1] = r1;
+    R1[2*i+1] = (uint16) r1;
   }
   
-  R0[760] = R1[380]-2295;
+  R0[760] = (int16) (R1[380]-2295);
   for (i = 379;i >= 0;--i) {
     r2 = R1[i];
     r2 = (r2<<8)|*--s;
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,4591);
-    R0[2*i] = r0-2295;
+    R0[2*i] = (int16) (r0-2295);
     r1 = uint32_mod_uint14(r1,4591); /* needed only for invalid inputs */
-    R0[2*i+1] = r1-2295;
+    R0[2*i+1] = (int16) (r1-2295);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/761xint16/ref/decode.c supercop-20200826-patched/crypto_decode/761xint16/ref/decode.c
