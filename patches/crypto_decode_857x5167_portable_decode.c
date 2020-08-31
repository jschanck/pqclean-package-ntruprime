--- supercop-20200826/crypto_decode/857x5167/portable/decode.c	2020-08-31 19:56:55.571747944 -0400
+++ supercop-20200826-patched/crypto_decode/857x5167/portable/decode.c	2020-08-31 20:09:19.775726948 -0400
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
@@ -83,26 +83,26 @@
   r1 = (r1<<8)|*--s;
   r1 = (r1<<8)|*--s;
   r1 = uint32_mod_uint14(r1,6225); /* needed only for invalid inputs */
-  R10[0] = r1;
+  R10[0] = (uint16) r1;
   
   r2 = R10[0];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,5476);
   R9[0] = r0;
   r1 = uint32_mod_uint14(r1,291); /* needed only for invalid inputs */
-  R9[1] = r1;
+  R9[1] = (uint16) r1;
   
   r2 = R9[1];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,74);
   R8[2] = r0;
   r1 = uint32_mod_uint14(r1,1004); /* needed only for invalid inputs */
-  R8[3] = r1;
+  R8[3] = (uint16) r1;
   r2 = R9[0];
   uint32_divmod_uint14(&r1,&r0,r2,74);
   R8[0] = r0;
   r1 = uint32_mod_uint14(r1,74); /* needed only for invalid inputs */
-  R8[1] = r1;
+  R8[1] = (uint16) r1;
   
   R7[6] = R8[3];
   for (i = 2;i >= 0;--i) {
@@ -112,7 +112,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,2194);
     R7[2*i] = r0;
     r1 = uint32_mod_uint14(r1,2194); /* needed only for invalid inputs */
-    R7[2*i+1] = r1;
+    R7[2*i+1] = (uint16) r1;
   }
   
   r2 = R7[6];
@@ -121,7 +121,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,11991);
   R6[12] = r0;
   r1 = uint32_mod_uint14(r1,5483); /* needed only for invalid inputs */
-  R6[13] = r1;
+  R6[13] = (uint16) r1;
   for (i = 5;i >= 0;--i) {
     r2 = R7[i];
     r2 = (r2<<8)|*--s;
@@ -129,7 +129,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,11991);
     R6[2*i] = r0;
     r1 = uint32_mod_uint14(r1,11991); /* needed only for invalid inputs */
-    R6[2*i+1] = r1;
+    R6[2*i+1] = (uint16) r1;
   }
   
   R5[26] = R6[13];
@@ -139,7 +139,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,1752);
     R5[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1752); /* needed only for invalid inputs */
-    R5[2*i+1] = r1;
+    R5[2*i+1] = (uint16) r1;
   }
   
   r2 = R5[26];
@@ -147,7 +147,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,10713);
   R4[52] = r0;
   r1 = uint32_mod_uint14(r1,131); /* needed only for invalid inputs */
-  R4[53] = r1;
+  R4[53] = (uint16) r1;
   for (i = 25;i >= 0;--i) {
     r2 = R5[i];
     r2 = (r2<<8)|*--s;
@@ -155,7 +155,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,10713);
     R4[2*i] = r0;
     r1 = uint32_mod_uint14(r1,10713); /* needed only for invalid inputs */
-    R4[2*i+1] = r1;
+    R4[2*i+1] = (uint16) r1;
   }
   
   r2 = R4[53];
@@ -164,14 +164,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,1656);
   R3[106] = r0;
   r1 = uint32_mod_uint14(r1,5167); /* needed only for invalid inputs */
-  R3[107] = r1;
+  R3[107] = (uint16) r1;
   for (i = 52;i >= 0;--i) {
     r2 = R4[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1656);
     R3[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1656); /* needed only for invalid inputs */
-    R3[2*i+1] = r1;
+    R3[2*i+1] = (uint16) r1;
   }
   
   R2[214] = R3[107];
@@ -181,7 +181,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,651);
     R2[2*i] = r0;
     r1 = uint32_mod_uint14(r1,651); /* needed only for invalid inputs */
-    R2[2*i+1] = r1;
+    R2[2*i+1] = (uint16) r1;
   }
   
   R1[428] = R2[214];
@@ -191,17 +191,17 @@
     uint32_divmod_uint14(&r1,&r0,r2,408);
     R1[2*i] = r0;
     r1 = uint32_mod_uint14(r1,408); /* needed only for invalid inputs */
-    R1[2*i+1] = r1;
+    R1[2*i+1] = (uint16) r1;
   }
   
-  R0[856] = R1[428]-2583;
+  R0[856] = (int16) (R1[428]-2583);
   for (i = 427;i >= 0;--i) {
     r2 = R1[i];
     r2 = (r2<<8)|*--s;
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,5167);
-    R0[2*i] = r0-2583;
+    R0[2*i] = (int16) (r0-2583);
     r1 = uint32_mod_uint14(r1,5167); /* needed only for invalid inputs */
-    R0[2*i+1] = r1-2583;
+    R0[2*i+1] = (int16) (r1-2583);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/857xint16/ref/decode.c supercop-20200826-patched/crypto_decode/857xint16/ref/decode.c
