--- supercop-20200826/crypto_encode/857x5167/avx/encode.c	2020-08-31 09:55:07.105787778 -0400
+++ supercop-20200826-patched/crypto_encode/857x5167/avx/encode.c	2020-08-31 07:48:47.766917231 -0400
@@ -19,6 +19,7 @@
   uint16 *writing;
   uint16 r0,r1;
   uint32 r2;
+  uint32 s0;
   
   reading = (uint16 *) R0;
   writing = R;
@@ -85,11 +86,18 @@
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
   R[214] = R[428];
   
@@ -115,11 +123,18 @@
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
   R[107] = R[214];
   
@@ -145,11 +160,18 @@
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
   r0 = R[106];
   r1 = R[107];
@@ -223,11 +245,18 @@
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
   R[13] = R[26];
   
@@ -268,5 +297,5 @@
   
   r0 = R[0];
   *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857x5167/portable/encode.c supercop-20200826-patched/crypto_encode/857x5167/portable/encode.c
