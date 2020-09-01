--- supercop-20200826/crypto_decode/653x4621/portable/decode.c	2020-08-31 20:12:38.909042259 -0400
+++ supercop-20200826-patched/crypto_decode/653x4621/portable/decode.c	2020-08-31 20:09:19.759726834 -0400
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
   r1 = uint32_mod_uint14(r1,86); /* needed only for invalid inputs */
-  R10[0] = r1;
+  R10[0] = (uint16) r1;
   
   r2 = R10[0];
   r2 = (r2<<8)|*--s;
@@ -90,7 +90,7 @@
   uint32_divmod_uint14(&r1,&r0,r2,835);
   R9[0] = r0;
   r1 = uint32_mod_uint14(r1,6708); /* needed only for invalid inputs */
-  R9[1] = r1;
+  R9[1] = (uint16) r1;
   
   R8[2] = R9[1];
   r2 = R9[0];
@@ -99,19 +99,19 @@
   uint32_divmod_uint14(&r1,&r0,r2,7396);
   R8[0] = r0;
   r1 = uint32_mod_uint14(r1,7396); /* needed only for invalid inputs */
-  R8[1] = r1;
+  R8[1] = (uint16) r1;
   
   r2 = R8[2];
   uint32_divmod_uint14(&r1,&r0,r2,86);
   R7[4] = r0;
   r1 = uint32_mod_uint14(r1,78); /* needed only for invalid inputs */
-  R7[5] = r1;
+  R7[5] = (uint16) r1;
   for (i = 1;i >= 0;--i) {
     r2 = R8[i];
     uint32_divmod_uint14(&r1,&r0,r2,86);
     R7[2*i] = r0;
     r1 = uint32_mod_uint14(r1,86); /* needed only for invalid inputs */
-    R7[2*i+1] = r1;
+    R7[2*i+1] = (uint16) r1;
   }
   
   R6[10] = R7[5];
@@ -122,7 +122,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,2370);
     R6[2*i] = r0;
     r1 = uint32_mod_uint14(r1,2370); /* needed only for invalid inputs */
-    R6[2*i+1] = r1;
+    R6[2*i+1] = (uint16) r1;
   }
   
   R5[20] = R6[10];
@@ -133,7 +133,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,12461);
     R5[2*i] = r0;
     r1 = uint32_mod_uint14(r1,12461); /* needed only for invalid inputs */
-    R5[2*i+1] = r1;
+    R5[2*i+1] = (uint16) r1;
   }
   
   R4[40] = R5[20];
@@ -143,7 +143,7 @@
     uint32_divmod_uint14(&r1,&r0,r2,1786);
     R4[2*i] = r0;
     r1 = uint32_mod_uint14(r1,1786); /* needed only for invalid inputs */
-    R4[2*i+1] = r1;
+    R4[2*i+1] = (uint16) r1;
   }
   
   r2 = R4[40];
@@ -152,14 +152,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,676);
   R3[80] = r0;
   r1 = uint32_mod_uint14(r1,7510); /* needed only for invalid inputs */
-  R3[81] = r1;
+  R3[81] = (uint16) r1;
   for (i = 39;i >= 0;--i) {
     r2 = R4[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,676);
     R3[2*i] = r0;
     r1 = uint32_mod_uint14(r1,676); /* needed only for invalid inputs */
-    R3[2*i+1] = r1;
+    R3[2*i+1] = (uint16) r1;
   }
   
   r2 = R3[81];
@@ -167,14 +167,14 @@
   uint32_divmod_uint14(&r1,&r0,r2,416);
   R2[162] = r0;
   r1 = uint32_mod_uint14(r1,4621); /* needed only for invalid inputs */
-  R2[163] = r1;
+  R2[163] = (uint16) r1;
   for (i = 80;i >= 0;--i) {
     r2 = R3[i];
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,416);
     R2[2*i] = r0;
     r1 = uint32_mod_uint14(r1,416); /* needed only for invalid inputs */
-    R2[2*i+1] = r1;
+    R2[2*i+1] = (uint16) r1;
   }
   
   R1[326] = R2[163];
@@ -184,17 +184,17 @@
     uint32_divmod_uint14(&r1,&r0,r2,326);
     R1[2*i] = r0;
     r1 = uint32_mod_uint14(r1,326); /* needed only for invalid inputs */
-    R1[2*i+1] = r1;
+    R1[2*i+1] = (uint16) r1;
   }
   
-  R0[652] = R1[326]-2310;
+  R0[652] = (int16) (R1[326]-2310);
   for (i = 325;i >= 0;--i) {
     r2 = R1[i];
     r2 = (r2<<8)|*--s;
     r2 = (r2<<8)|*--s;
     uint32_divmod_uint14(&r1,&r0,r2,4621);
-    R0[2*i] = r0-2310;
+    R0[2*i] = (int16) (r0-2310);
     r1 = uint32_mod_uint14(r1,4621); /* needed only for invalid inputs */
-    R0[2*i+1] = r1-2310;
+    R0[2*i+1] = (int16) (r1-2310);
   }
 }
diff -ru --no-dereference supercop-20200826/crypto_decode/653xint16/ref/decode.c supercop-20200826-patched/crypto_decode/653xint16/ref/decode.c
