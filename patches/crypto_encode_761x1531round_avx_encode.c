--- supercop-20200826/crypto_encode/761x1531round/avx/encode.c	2020-08-28 13:06:31.005178967 -0400
+++ supercop-20200826-patched/crypto_encode/761x1531round/avx/encode.c	2020-08-28 12:40:39.797208729 -0400
@@ -19,6 +19,7 @@
   uint16 *writing;
   uint16 r0,r1;
   uint32 r2;
+  uint32 s0;
   
   reading = (uint16 *) R0;
   writing = R;
@@ -47,11 +48,18 @@
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
   R[380] = (((3*((10923*R0[760]+16384)>>15)+2295)&16383)*10923)>>15;
   
@@ -116,11 +124,18 @@
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
   
@@ -174,11 +189,18 @@
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
@@ -203,11 +225,18 @@
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
@@ -243,5 +272,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/761x3/avx/encode.c supercop-20200826-patched/crypto_encode/761x3/avx/encode.c
