--- supercop-20200826/crypto_decode/857x1723/portable/decode.c	2020-08-31 20:12:38.929042383 -0400
+++ supercop-20200826-patched/crypto_decode/857x1723/portable/decode.c	2020-08-31 20:09:19.771726919 -0400
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
@@ -82,7 +82,7 @@
   r1 = 0;
   r1 = (r1<<8)|*--s;
   r1 = uint32_mod_uint14(r1,160); /* needed only for invalid inputs */
-  R10[0] = r1;
+  R10[0] = (uint16) r1;
   
   r2 = R10[0];
   r2 = (r2<<8)|*--s;
@@ -90,20 +90,20 @@
   uint32_divmod_uint14(&r1,&r0,r2,743);
   R9[0] = r0;
   r1 = uint32_mod_uint14(r1,14044); /* needed only for invalid inputs */
-  R9[1] = r1;
+  R9[1] = (uint16) r1;
   
   r2 = R9[1];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,436);
   R8[2] = r0;
   r1 = uint32_mod_uint14(r1,8246); /* needed only for invalid inputs */
-  R8[3] = r1;
+  R8[3] = (uint16) r1;
   r2 = R9[0];
   r2 = (r2<<8)|*--s;
   uint32_divmod_uint14(&r1,&r0,r2,436);
   R8[0] = r0;
   r1 = uint32_mod_uint14(r1,436); /* needed only for invalid inputs */
-  R8[1] = r1;
+  R8[1] = (uint16) r1;
   
   R7[6] = R8[3];
   for (i = 2;i >= 0;--i) {
@@ -112,7 +112,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,334);
     R7[2*i] = r0;
     r1 = uint32_mod_uint14(r1,334); /* needed only for invalid inputs */
-    R7[2*i+1] = r1;
+    R7[2*i+1] = (uint16) r1;
   }
   
   r2 = R7[6];
@@ -120,14 +120,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,292);
   R6[12] = r0;
   r1 = uint32_mod_uint14(r1,7229); /* needed only for invalid inputs */
-  R6[13] = r1;
+  R6[13] = (uint16) r1;
   for (i = 5;i >= 0;--i) {
     r2 = R7[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,292);
     R6[2*i] = r0;
     r1 = uint32_mod_uint14(r1,292); /* needed only for invalid inputs */
-    R6[2*i+1] = r1;
+    R6[2*i+1] = (uint16) r1;
   }
   
   R5[26] = R6[13];
@@ -137,7 +137,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,273);
     R5[2*i] = r0;
     r1 = uint32_mod_uint14(r1,273); /* needed only for invalid inputs */
-    R5[2*i+1] = r1;
+    R5[2*i+1] = (uint16) r1;
   }
   
   r2 = R5[26];
@@ -145,7 +145,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,4225);
   R4[52] = r0;
   r1 = uint32_mod_uint14(r1,438); /* needed only for invalid inputs */
-  R4[53] = r1;
+  R4[53] = (uint16) r1;
   for (i = 25;i >= 0;--i) {
     r2 = R5[i];
     r2 = (r2<<8)|*--s;
@@ -153,7 +153,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,4225);
     R4[2*i] = r0;
     r1 = uint32_mod_uint14(r1,4225); /* needed only for invalid inputs */
-    R4[2*i+1] = r1;
+    R4[2*i+1] = (uint16) r1;
   }
   
   r2 = R4[53];
@@ -161,13 +161,13 @@
   uint32_divmod_uint14(&r1,&r0,r2,65);
   R3[106] = r0;
   r1 = uint32_mod_uint14(r1,1723); /* needed only for invalid inputs */
-  R3[107] = r1;
+  R3[107] = (uint16) r1;
   for (i = 52;i >= 0;--i) {
     r2 = R4[i];
     uint32_divmod_uint14(&r1,&r0,r2,65);
     R3[2*i] = r0;
     r1 = uint32_mod_uint14(r1,65); /* needed only for invalid inputs */
-    R3[2*i+1] = r1;
+    R3[2*i+1] = (uint16) r1;
   }
   
   R2[214] = R3[107];
@@ -178,7 +178,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,2053);
     R2[2*i] = r0;
     r1 = uint32_mod_uint14(r1,2053); /* needed only for invalid inputs */
-    R2[2*i+1] = r1;
+    R2[2*i+1] = (uint16) r1;
   }
   
   R1[428] = R2[214];
@@ -189,16 +189,16 @@
     uint32_divmod_uint14(&r1,&r0,r2,11597);
     R1[2*i] = r0;
     r1 = uint32_mod_uint14(r1,11597); /* needed only for invalid inputs */
-    R1[2*i+1] = r1;
+    R1[2*i+1] = (uint16) r1;
   }
   
-  R0[856] = 3*R1[428]-2583;
+  R0[856] = (int16) (3*R1[428]-2583);
   for (i = 427;i >= 0;--i) {
     r2 = R1[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,1723);
-    R0[2*i] = 3*r0-2583;
+    R0[2*i] = (int16) (3*r0-2583);
     r1 = uint32_mod_uint14(r1,1723); /* needed only for invalid inputs */
-    R0[2*i+1] = 3*r1-2583;
+    R0[2*i+1] = (int16) (3*r1-2583);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/857x5167/avx/decode.c supercop-20200826-patched/crypto_decode/857x5167/avx/decode.c
