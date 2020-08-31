--- supercop-20200826/crypto_core/inv3sntrup857/avx/r3_recip.c	2020-08-31 19:56:55.491746618 -0400
+++ supercop-20200826-patched/crypto_core/inv3sntrup857/avx/r3_recip.c	2020-08-31 20:09:19.691726351 -0400
@@ -162,7 +162,7 @@
   vec256_tobits(V1,v1);
 
   for (i = 0;i < ppad;++i)
-    v[i] = v0[i] + 2*v1[i] - 4*(v0[i]&v1[i]);
+    v[i] = (small) (v0[i] + 2*v1[i] - 4*(v0[i]&v1[i]));
 
   for (i = 0;i < ppad;++i) vrev[i] = v[ppad-1-i];
   for (i = ppad;i < ppad+(ppad-p);++i) vrev[i] = 0;
@@ -234,11 +234,11 @@
 {
   vec256 f0 = f[0];
 
-  unsigned long long low0 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
+  unsigned long long low0 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
 
   low0 = low0 >> 1;
 
-  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,low0),0x3);
+  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,(long long) low0),0x3);
 
   f[0] = _mm256_permute4x64_epi64(f0,0x39);
 }
@@ -248,14 +248,14 @@
   vec256 f0 = f[0];
   vec256 f1 = f[1];
 
-  unsigned long long low0 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
-  unsigned long long low1 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
+  unsigned long long low0 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
+  unsigned long long low1 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
 
   low0 = (low0 >> 1) | (low1 << 63);
   low1 = low1 >> 1;
 
-  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,low0),0x3);
-  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,low1),0x3);
+  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,(long long) low0),0x3);
+  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,(long long) low1),0x3);
 
   f[0] = _mm256_permute4x64_epi64(f0,0x39);
   f[1] = _mm256_permute4x64_epi64(f1,0x39);
@@ -267,17 +267,17 @@
   vec256 f1 = f[1];
   vec256 f2 = f[2];
 
-  unsigned long long low0 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
-  unsigned long long low1 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
-  unsigned long long low2 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
+  unsigned long long low0 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
+  unsigned long long low1 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
+  unsigned long long low2 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
 
   low0 = (low0 >> 1) | (low1 << 63);
   low1 = (low1 >> 1) | (low2 << 63);
   low2 = low2 >> 1;
 
-  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,low0),0x3);
-  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,low1),0x3);
-  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,low2),0x3);
+  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,(long long) low0),0x3);
+  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,(long long) low1),0x3);
+  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,(long long) low2),0x3);
 
   f[0] = _mm256_permute4x64_epi64(f0,0x39);
   f[1] = _mm256_permute4x64_epi64(f1,0x39);
@@ -291,20 +291,20 @@
   vec256 f2 = f[2];
   vec256 f3 = f[3];
 
-  unsigned long long low0 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
-  unsigned long long low1 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
-  unsigned long long low2 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
-  unsigned long long low3 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f3));
+  unsigned long long low0 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
+  unsigned long long low1 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
+  unsigned long long low2 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
+  unsigned long long low3 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f3));
 
   low0 = (low0 >> 1) | (low1 << 63);
   low1 = (low1 >> 1) | (low2 << 63);
   low2 = (low2 >> 1) | (low3 << 63);
   low3 = low3 >> 1;
 
-  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,low0),0x3);
-  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,low1),0x3);
-  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,low2),0x3);
-  f3 = _mm256_blend_epi32(f3,_mm256_set_epi64x(0,0,0,low3),0x3);
+  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,(long long) low0),0x3);
+  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,(long long) low1),0x3);
+  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,(long long) low2),0x3);
+  f3 = _mm256_blend_epi32(f3,_mm256_set_epi64x(0,0,0,(long long) low3),0x3);
 
   f[0] = _mm256_permute4x64_epi64(f0,0x39);
   f[1] = _mm256_permute4x64_epi64(f1,0x39);
@@ -316,11 +316,11 @@
 {
   vec256 f0 = _mm256_permute4x64_epi64(f[0],0x93);
 
-  unsigned long long low0 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
+  unsigned long long low0 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
 
   low0 = low0 << 1;
 
-  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,low0),0x3);
+  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,(long long) low0),0x3);
 
   f[0] = f0;
 }
@@ -330,14 +330,14 @@
   vec256 f0 = _mm256_permute4x64_epi64(f[0],0x93);
   vec256 f1 = _mm256_permute4x64_epi64(f[1],0x93);
 
-  unsigned long long low0 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
-  unsigned long long low1 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
+  unsigned long long low0 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
+  unsigned long long low1 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
 
   low1 = (low1 << 1) | (low0 >> 63);
   low0 = low0 << 1;
 
-  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,low0),0x3);
-  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,low1),0x3);
+  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,(long long) low0),0x3);
+  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,(long long) low1),0x3);
 
   f[0] = f0;
   f[1] = f1;
@@ -351,7 +351,7 @@
 
   unsigned long long low0 = *(unsigned long long *) &f0;
   unsigned long long low1 = *(unsigned long long *) &f1;
-  unsigned long long low2 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
+  unsigned long long low2 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
 
   low2 = (low2 << 1) | (low1 >> 63);
   low1 = (low1 << 1) | (low0 >> 63);
@@ -359,7 +359,7 @@
 
   *(unsigned long long *) &f0 = low0;
   *(unsigned long long *) &f1 = low1;
-  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,low2),0x3);
+  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,(long long) low2),0x3);
 
   f[0] = f0;
   f[1] = f1;
@@ -373,20 +373,20 @@
   vec256 f2 = _mm256_permute4x64_epi64(f[2],0x93);
   vec256 f3 = _mm256_permute4x64_epi64(f[3],0x93);
 
-  unsigned long long low0 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
-  unsigned long long low1 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
-  unsigned long long low2 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
-  unsigned long long low3 = _mm_cvtsi128_si64(_mm256_castsi256_si128(f3));
+  unsigned long long low0 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f0));
+  unsigned long long low1 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f1));
+  unsigned long long low2 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f2));
+  unsigned long long low3 = (unsigned long long) _mm_cvtsi128_si64(_mm256_castsi256_si128(f3));
 
   low3 = (low3 << 1) | (low2 >> 63);
   low2 = (low2 << 1) | (low1 >> 63);
   low1 = (low1 << 1) | (low0 >> 63);
   low0 = low0 << 1;
 
-  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,low0),0x3);
-  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,low1),0x3);
-  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,low2),0x3);
-  f3 = _mm256_blend_epi32(f3,_mm256_set_epi64x(0,0,0,low3),0x3);
+  f0 = _mm256_blend_epi32(f0,_mm256_set_epi64x(0,0,0,(long long) low0),0x3);
+  f1 = _mm256_blend_epi32(f1,_mm256_set_epi64x(0,0,0,(long long) low1),0x3);
+  f2 = _mm256_blend_epi32(f2,_mm256_set_epi64x(0,0,0,(long long) low2),0x3);
+  f3 = _mm256_blend_epi32(f3,_mm256_set_epi64x(0,0,0,(long long) low3),0x3);
 
   f[0] = f0;
   f[1] = f1;
@@ -643,6 +643,6 @@
   vec256_scale(V0,V1,c0vec,c1vec);
 
   vec256_final(out,V0,V1);
-  out[p] = negative_mask(minusdelta);
+  out[p] = (small) negative_mask(minusdelta);
   return 0;
 }
diff -ru --no-dereference supercop-20200826/crypto_core/inv3sntrup857/ref/recip.c supercop-20200826-patched/crypto_core/inv3sntrup857/ref/recip.c
