--- supercop-20200826/crypto_encode/761x1531/avx/encode.c	2020-08-31 09:55:07.085788034 -0400
+++ supercop-20200826-patched/crypto_encode/761x1531/avx/encode.c	2020-08-31 07:48:47.742932619 -0400
@@ -19,6 +19,7 @@
   uint16 *writing;
   uint16 r0,r1;
   uint32 r2;
+  uint32 s0;
   
   reading = (uint16 *) R0;
   writing = R;
@@ -45,11 +46,18 @@
       ));
     x = _mm256_permute4x64_epi64(x,0xd8);
     _mm_storeu_si128((__m128i *) writing,_mm256_extractf128_si256(x,0));
-    *((uint32 *) (out+0)) = _mm256_extract_epi32(x,4);
-    *((uint32 *) (out+4)) = _mm256_extract_epi32(x,6);
+    s0 = _mm256_extract_epi32(x,4);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
+    s0 = _mm256_extract_epi32(x,6);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
     reading += 16;
     writing += 8;
-    out += 8;
   }
   R[380] = (((R0[760]+2295)&16383)*10923)>>15;
   
@@ -114,11 +122,18 @@
       ));
     x = _mm256_permute4x64_epi64(x,0xd8);
     _mm_storeu_si128((__m128i *) writing,_mm256_extractf128_si256(x,0));
-    *((uint32 *) (out+0)) = _mm256_extract_epi32(x,4);
-    *((uint32 *) (out+4)) = _mm256_extract_epi32(x,6);
+    s0 = _mm256_extract_epi32(x,4);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
+    s0 = _mm256_extract_epi32(x,6);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
     reading += 16;
     writing += 8;
-    out += 8;
   }
   R[95] = R[190];
   
@@ -172,11 +187,18 @@
       ));
     x = _mm256_permute4x64_epi64(x,0xd8);
     _mm_storeu_si128((__m128i *) writing,_mm256_extractf128_si256(x,0));
-    *((uint32 *) (out+0)) = _mm256_extract_epi32(x,4);
-    *((uint32 *) (out+4)) = _mm256_extract_epi32(x,6);
+    s0 = _mm256_extract_epi32(x,4);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
+    s0 = _mm256_extract_epi32(x,6);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
     reading += 16;
     writing += 8;
-    out += 8;
   }
   
   reading = (uint16 *) R;
@@ -201,11 +223,18 @@
       ));
     x = _mm256_permute4x64_epi64(x,0xd8);
     _mm_storeu_si128((__m128i *) writing,_mm256_extractf128_si256(x,0));
-    *((uint32 *) (out+0)) = _mm256_extract_epi32(x,4);
-    *((uint32 *) (out+4)) = _mm256_extract_epi32(x,6);
+    s0 = _mm256_extract_epi32(x,4);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
+    s0 = _mm256_extract_epi32(x,6);
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0; s0 >>= 8;
+    *out++ = s0;
     reading += 16;
     writing += 8;
-    out += 8;
   }
   
   for (i = 0;i < 6;++i) {
@@ -241,5 +270,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/761x1531/portable/encode.c supercop-20200826-patched/crypto_encode/761x1531/portable/encode.c
