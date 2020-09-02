--- supercop-20200826/crypto_core/mult3sntrup857/avx/mult1024.c
+++ supercop-20200826-patched/crypto_core/mult3sntrup857/avx/mult1024.c
@@ -15,6 +15,26 @@
 #define mulhrs_x16 _mm256_mulhrs_epi16
 #define signmask_x16(x) _mm256_srai_epi16((x),15)
 
+typedef union {
+  int16 v[512];
+  int16x16 _dummy;
+} vec512;
+
+typedef union {
+  int16 v[4][512];
+  int16x16 _dummy;
+} vec4x512;
+
+typedef union {
+  int16 v[1024];
+  int16x16 _dummy;
+} vec1024;
+
+typedef union {
+  int16 v[4*512];
+  int16x16 _dummy;
+} vec2048;
+
 static int16x16 squeeze_3_x16(int16x16 x)
 {
   return sub_x16(x,mullo_x16(mulhrs_x16(x,const_x16(10923)),const_x16(3)));
@@ -69,9 +89,10 @@
     store_x16(&fpad[3][j],f3);
   }
 
-  for (i = 0;i < 4;++i)
+  for (i = 0;i < 4;++i) {
     for (j = 256;j < 512;++j)
       fpad[i][j] = 0;
+  }
 }
 
 static void unstride(int16 f[2048],const int16 fpad[4][512])
@@ -106,18 +127,49 @@
   }
 }
 
-#define ALIGNED __attribute((aligned(32)))
-
-static const ALIGNED int16 y_7681[512] = {
-#include "precomp7681.inc"
-} ;
+static const vec512 y_7681 = { .v = {
+-3593,-617,-2804,3266,-2194,-1296,-1321,810,1414,3706,-549,-396,-121,-2088,-2555,1305,
+-3777,1921,103,3600,-2456,1483,1399,-1887,-1701,2006,1535,-3174,-2250,2816,-2440,-1760,
+-3625,2830,2043,-3689,1100,1525,-514,7,2876,-1599,3153,-1881,-2495,-2237,-2535,438,
+3182,3364,-1431,1738,3696,-2557,-2956,638,-2319,-1993,-2310,-3555,834,-1986,3772,-679,
+3593,617,2804,-3266,2194,1296,1321,-810,-1414,-3706,549,396,121,2088,2555,-1305,
+3777,-1921,-103,-3600,2456,-1483,-1399,1887,1701,-2006,-1535,3174,2250,-2816,2440,1760,
+3625,-2830,-2043,3689,-1100,-1525,514,-7,-2876,1599,-3153,1881,2495,2237,2535,-438,
+-3182,-3364,1431,-1738,-3696,2557,2956,-638,2319,1993,2310,3555,-834,1986,-3772,679,
+2665,727,-2572,2426,-2133,-1386,1681,-1054,2579,3750,373,3417,404,-2233,3135,-3405,
+-1799,1521,1497,-3831,-3480,-3428,2883,-1698,-859,-2762,2175,-194,-486,-3816,-1756,2385,
+-783,1533,3145,2,3310,-2743,2224,-1166,2649,-1390,3692,2789,1919,2835,-2391,-2732,
+1056,1464,1350,-915,-1168,-921,-3588,3456,-2160,-1598,730,2919,1532,-2764,-660,-2113,
+-2665,-727,2572,-2426,2133,1386,-1681,1054,-2579,-3750,-373,-3417,-404,2233,-3135,3405,
+1799,-1521,-1497,3831,3480,3428,-2883,1698,859,2762,-2175,194,486,3816,1756,-2385,
+783,-1533,-3145,-2,-3310,2743,-2224,1166,-2649,1390,-3692,-2789,-1919,-2835,2391,2732,
+-1056,-1464,-1350,915,1168,921,3588,-3456,2160,1598,-730,-2919,-1532,2764,660,2113,
+2005,-188,2345,-3723,-1403,2070,83,-3214,-3752,-1012,1837,-3208,3287,3335,-293,796,
+592,1519,-1338,1931,509,-2262,-3408,3334,3677,2130,642,589,-2167,-1084,-370,-3163,
+3763,-893,-2303,-402,2937,-1689,-1526,-3745,-2460,2874,2965,124,-1669,-1441,-3312,3781,
+2812,-2386,-2515,-429,-3343,777,-826,-3366,-3657,-1404,-791,-2963,-692,2532,2083,2258,
+-2005,188,-2345,3723,1403,-2070,-83,3214,3752,1012,-1837,3208,-3287,-3335,293,-796,
+-592,-1519,1338,-1931,-509,2262,3408,-3334,-3677,-2130,-642,-589,2167,1084,370,3163,
+-3763,893,2303,402,-2937,1689,1526,3745,2460,-2874,-2965,-124,1669,1441,3312,-3781,
+-2812,2386,2515,429,3343,-777,826,3366,3657,1404,791,2963,692,-2532,-2083,-2258,
+179,1121,2891,-3581,3177,-658,-3314,-1509,-17,151,2815,2786,1278,-2767,-1072,-1151,
+-1242,-2071,2340,-1586,2072,1476,2998,2918,-3744,-3794,-1295,451,-929,2378,-1144,434,
+-1070,-436,-3550,-3568,1649,715,3461,-1407,-2001,-1203,3770,1712,2230,-3542,2589,-3547,
+-2059,-236,3434,-3693,2161,-670,2719,2339,-2422,1181,3450,222,1348,-226,2247,-1779,
+-179,-1121,-2891,3581,-3177,658,3314,1509,17,-151,-2815,-2786,-1278,2767,1072,1151,
+1242,2071,-2340,1586,-2072,-1476,-2998,-2918,3744,3794,1295,-451,929,-2378,1144,-434,
+1070,436,3550,3568,-1649,-715,-3461,1407,2001,1203,-3770,-1712,-2230,3542,-2589,3547,
+2059,236,-3434,3693,-2161,670,-2719,-2339,2422,-1181,-3450,-222,-1348,226,-2247,1779,
+} } ;
 
 static void mult1024(int16 h[2048],const int16 f[1024],const int16 g[1024])
 {
-  ALIGNED int16 fpad[4][512];
-  ALIGNED int16 gpad[4][512];
-  ALIGNED int16 h_7681[2048];
+  vec4x512 x1, x2;
+  vec2048 x3;
+#define fpad (x1.v)
+#define gpad (x2.v)
 #define hpad fpad
+#define h_7681 (x3.v)
   int i;
 
   stride(fpad,f);
@@ -159,7 +211,7 @@
     int16x16 h4 = sub_x16(d1d2d3,e13);
     int16x16 h5 = sub_x16(d2d3,e23);
     int16x16 h6 = d3;
-    int16x16 twist = load_x16(&y_7681[i]);
+    int16x16 twist = load_x16(&y_7681.v[i]);
     h4 = mulmod_7681_x16(h4,twist);
     h5 = mulmod_7681_x16(h5,twist);
     h6 = mulmod_7681_x16(h6,twist);
@@ -173,7 +225,7 @@
   }
 
   invntt512_7681(hpad[0],4);
-  unstride(h_7681,hpad);
+  unstride(h_7681,(const int16(*)[512]) hpad);
 
   for (i = 0;i < 2048;i += 16) {
     int16x16 u = load_x16(&h_7681[i]);
@@ -202,9 +254,11 @@
 
 int crypto_core(unsigned char *outbytes,const unsigned char *inbytes,const unsigned char *kbytes,const unsigned char *cbytes)
 {
-  ALIGNED int16 f[1024];
-  ALIGNED int16 g[1024];
-  ALIGNED int16 fg[2048];
+  vec1024 x1, x2;
+  vec2048 x3;
+#define f (x1.v)
+#define g (x2.v)
+#define fg (x3.v)
 #define h f
   int i;
   int16x16 x;
@@ -214,19 +268,19 @@
   for (i = p&~15;i < 1024;i += 16) store_x16(&g[i],x);
 
   for (i = 0;i < p;++i) {
-    int8 fi = inbytes[i];
+    int8 fi = (int8) inbytes[i];
     int8 fi0 = fi&1;
-    f[i] = fi0-(fi&(fi0<<1));
+    f[i] = (int16) (fi0-(fi&(fi0<<1)));
   }
   for (i = 0;i < p;++i) {
-    int8 gi = kbytes[i];
+    int8 gi = (int8) kbytes[i];
     int8 gi0 = gi&1;
-    g[i] = gi0-(gi&(gi0<<1));
+    g[i] = (int16) (gi0-(gi&(gi0<<1)));
   }
 
   mult1024(fg,f,g);
 
-  fg[0] -= fg[p-1];
+  fg[0] = (int16) (fg[0] - fg[p-1]);
   for (i = 0;i < 1024;i += 16) {
     int16x16 fgi = load_x16(&fg[i]);
     int16x16 fgip = load_x16(&fg[i + p]);
@@ -236,7 +290,7 @@
     store_x16(&h[i],x);
   }
   
-  for (i = 0;i < p;++i) outbytes[i] = h[i];
+  for (i = 0;i < p;++i) outbytes[i] = (unsigned char) h[i];
 
   return 0;
 }

