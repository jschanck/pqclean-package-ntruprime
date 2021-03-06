--- supercop-20200826/crypto_core/multsntrup653/avx/ntt.c
+++ supercop-20200826-patched/crypto_core/multsntrup653/avx/ntt.c
@@ -9,16 +9,21 @@
 typedef int8_t int8;
 typedef int16_t int16;
 
-#define zeta(n,i) (i[(__m256i *) zeta_##n])
-#define zeta_x4(n,i) (i[(__m256i *) zeta_x4_##n])
-#define zeta_qinv(n,i) (i[(__m256i *) qinvzeta_##n])
-#define zeta_x4_qinv(n,i) (i[(__m256i *) qinvzeta_x4_##n])
-#define zetainv(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) zeta_##n+n/2+1-16*(i+1)))
-#define zetainv_x4(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) zeta_x4_##n+2*n+4-16*(i+1)))
-#define zetainv_qinv(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) qinvzeta_##n+n/2+1-16*(i+1)))
-#define zetainv_x4_qinv(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) qinvzeta_x4_##n+2*n+4-16*(i+1)))
+#define zeta(n,i) (((__m256i *) zeta_##n)[(i)])
+#define zeta_x4(n,i) (((__m256i *) zeta_x4_##n)[(i)])
+#define zeta_qinv(n,i) (((__m256i *) qinvzeta_##n)[(i)])
+#define zeta_x4_qinv(n,i) (((__m256i *) qinvzeta_x4_##n)[(i)])
+#define zetainv(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) zeta_##n+(n)/2+1-16*((i)+1)))
+#define zetainv_x4(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) zeta_x4_##n+2*(n)+4-16*((i)+1)))
+#define zetainv_qinv(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) qinvzeta_##n+(n)/2+1-16*((i)+1)))
+#define zetainv_x4_qinv(n,i) _mm256_loadu_reverse16((__m256i *) ((int16 *) qinvzeta_x4_##n+2*(n)+4-16*((i)+1)))
+
+typedef union {
+  int16 data[93*16];
+  __m256i _dummy;
+} vec1488;
 
-static const __attribute((aligned(32))) int16 qdata_7681[] = {
+static const vec1488 qdata_7681 = { .data = {
 
 #define q_x16 (qdata[0])
   7681,7681,7681,7681,7681,7681,7681,7681,7681,7681,7681,7681,7681,7681,7681,7681,
@@ -154,10 +159,10 @@
   -4496,-19215,-9360,26783,23668,-14138,27132,-32414,-25597,-2807,-5529,8831,-5913,17636,1869,-16638,
   -11655,9513,22124,25648,-24581,-21723,21953,-14129,22568,-15111,23225,26621,-20674,-15221,17030,-1715,
   9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
-
+  }
 };
 
-static const __attribute((aligned(32))) int16 qdata_10753[] = {
+static const vec1488 qdata_10753 = { .data = {
 
   10753,10753,10753,10753,10753,10753,10753,10753,10753,10753,10753,10753,10753,10753,10753,10753,
 
@@ -272,13 +277,13 @@
   -20856,-29541,-609,31924,-2316,3346,-8801,-13500,-7228,14237,11854,14780,-20490,-9374,780,16809,
   16072,11446,-17571,-8935,-14341,5369,-2066,-18918,18363,19863,17352,-16273,-12707,3699,17248,951,
   6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
-
+  }
 };
 
 static inline __m256i sub_x16(__m256i a,__m256i b)
 {
-  __asm__("vpsubw %1,%0,%0" : "+x"(a),"+x"(b));
-  return a;
+  //__asm__("vpsubw %1,%0,%0" : "+x"(a),"+x"(b));
+  return _mm256_sub_epi16(a,b);
 }
 
 static inline __m256i add_x16(__m256i a,__m256i b)
@@ -302,11 +307,16 @@
   return sub_x16(b,e);
 }
 
-static __attribute((aligned(32))) int8 shuffle_buf[32] = {
+typedef union {
+  int8 data[32];
+  __m256i _dummy;
+} byte32;
+static const byte32 shuffle_buf = { .data = {
   14,15,12,13,10,11,8,9,6,7,4,5,2,3,0,1,
   14,15,12,13,10,11,8,9,6,7,4,5,2,3,0,1,
+  }
 };
-#define shuffle (*(__m256i *) shuffle_buf)
+#define shuffle (*(__m256i *) shuffle_buf.data)
 
 static inline __m256i _mm256_loadu_reverse16(const __m256i *p)
 {
@@ -559,7 +569,7 @@
 
 static void ntt512(int16 *f,int reps,const __m256i *qdata)
 {
-  __m256i f0,f1,f2,f3,g0,g1,g2,g3,h0,h1,h2,h3;
+  __m256i f0,f1,f2,f3,g0,g1,g2,g3; /* [-Werror=unused-variable] */ /* ,h0,h1,h2,h3; */
   int16 *origf = f;
   int rep;
   __m256i zetainv_512[8];
@@ -604,12 +614,12 @@
 
 void ntt512_7681(int16 *f,int reps)
 {
-  ntt512(f,reps,(const __m256i *) qdata_7681);
+  ntt512(f,reps,(const __m256i *) qdata_7681.data);
 }
 
 void ntt512_10753(int16 *f,int reps)
 {
-  ntt512(f,reps,(const __m256i *) qdata_10753);
+  ntt512(f,reps,(const __m256i *) qdata_10753.data);
 }
 
 static void invntt128(int16 *f,int reps,const __m256i *qdata)
@@ -861,8 +871,8 @@
 
 static void invntt512(int16 *f,int reps,const __m256i *qdata)
 {
-  __m256i f0,f1,f2,f3,g0,g1,g2,g3,h0,h1,h2,h3;
-  int16 *origf = f;
+  __m256i f0,f1,f2,f3,g0,g1,g2,g3; /* [-Werror=unused-variable] */ /* ,h0,h1,h2,h3; */
+  /* [-Werror=unused-variable] */ /* int16 *origf = f; */
   int rep;
   __m256i zetainv_512[8];
   __m256i zetainv_qinv_512[8];
@@ -909,10 +919,10 @@
 
 void invntt512_7681(int16 *f,int reps)
 {
-  invntt512(f,reps,(const __m256i *) qdata_7681);
+  invntt512(f,reps,(const __m256i *) qdata_7681.data);
 }
 
 void invntt512_10753(int16 *f,int reps)
 {
-  invntt512(f,reps,(const __m256i *) qdata_10753);
+  invntt512(f,reps,(const __m256i *) qdata_10753.data);
 }

