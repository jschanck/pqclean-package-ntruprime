--- supercop-20200826/crypto_decode/653x1541/portable/decode.c	2020-08-31 20:12:38.905042235 -0400
+++ supercop-20200826-patched/crypto_decode/653x1541/portable/decode.c	2020-08-31 20:09:19.755726805 -0400
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
   r1 = uint32_mod_uint14(r1,2608); /* needed only for invalid inputs */
-  R10[0] = r1;
+  R10[0] = (uint16) r1;
   
   r2 = R10[0];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,71);
   R9[0] = r0;
   r1 = uint32_mod_uint14(r1,9402); /* needed only for invalid inputs */
-  R9[1] = r1;
+  R9[1] = (uint16) r1;
   
   R8[2] = R9[1];
   r2 = R9[0];
@@ -98,14 +98,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,134);
   R8[0] = r0;
   r1 = uint32_mod_uint14(r1,134); /* needed only for invalid inputs */
-  R8[1] = r1;
+  R8[1] = (uint16) r1;
   
   r2 = R8[2];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,2953);
   R7[4] = r0;
   r1 = uint32_mod_uint14(r1,815); /* needed only for invalid inputs */
-  R7[5] = r1;
+  R7[5] = (uint16) r1;
   for (i = 1;i >= 0;--i) {
     r2 = R8[i];
     r2 = (r2<<8)|*--s;
@@ -113,7 +113,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,2953);
     R7[2*i] = r0;
     r1 = uint32_mod_uint14(r1,2953); /* needed only for invalid inputs */
-    R7[2*i+1] = r1;
+    R7[2*i+1] = (uint16) r1;
   }
   
   R6[10] = R7[5];
@@ -124,7 +124,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,13910);
     R6[2*i] = r0;
     r1 = uint32_mod_uint14(r1,13910); /* needed only for invalid inputs */
-    R6[2*i+1] = r1;
+    R6[2*i+1] = (uint16) r1;
   }
   
   R5[20] = R6[10];
@@ -134,7 +134,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,1887);
     R5[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1887); /* needed only for invalid inputs */
-    R5[2*i+1] = r1;
+    R5[2*i+1] = (uint16) r1;
   }
   
   R4[40] = R5[20];
@@ -144,7 +144,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,695);
     R4[2*i] = r0;
     r1 = uint32_mod_uint14(r1,695); /* needed only for invalid inputs */
-    R4[2*i+1] = r1;
+    R4[2*i+1] = (uint16) r1;
   }
   
   r2 = R4[40];
@@ -153,7 +153,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,6745);
   R3[80] = r0;
   r1 = uint32_mod_uint14(r1,7910); /* needed only for invalid inputs */
-  R3[81] = r1;
+  R3[81] = (uint16) r1;
   for (i = 39;i >= 0;--i) {
     r2 = R4[i];
     r2 = (r2<<8)|*--s;
@@ -161,7 +161,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,6745);
     R3[2*i] = r0;
     r1 = uint32_mod_uint14(r1,6745); /* needed only for invalid inputs */
-    R3[2*i+1] = r1;
+    R3[2*i+1] = (uint16) r1;
   }
   
   r2 = R3[81];
@@ -169,14 +169,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,1314);
   R2[162] = r0;
   r1 = uint32_mod_uint14(r1,1541); /* needed only for invalid inputs */
-  R2[163] = r1;
+  R2[163] = (uint16) r1;
   for (i = 80;i >= 0;--i) {
     r2 = R3[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1314);
     R2[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1314); /* needed only for invalid inputs */
-    R2[2*i+1] = r1;
+    R2[2*i+1] = (uint16) r1;
   }
   
   R1[326] = R2[163];
@@ -187,16 +187,16 @@
     uint32_divmod_uint14(&r1,&r0,r2,9277);
     R1[2*i] = r0;
     r1 = uint32_mod_uint14(r1,9277); /* needed only for invalid inputs */
-    R1[2*i+1] = r1;
+    R1[2*i+1] = (uint16) r1;
   }
   
-  R0[652] = 3*R1[326]-2310;
+  R0[652] = (int16) (3*R1[326]-2310);
   for (i = 325;i >= 0;--i) {
     r2 = R1[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1541);
-    R0[2*i] = 3*r0-2310;
+    R0[2*i] = (int16) (3*r0-2310);
     r1 = uint32_mod_uint14(r1,1541); /* needed only for invalid inputs */
-    R0[2*i+1] = 3*r1-2310;
+    R0[2*i+1] = (int16) (3*r1-2310);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/653x4621/avx/decode.c supercop-20200826-patched/crypto_decode/653x4621/avx/decode.c
