--- supercop-20200826/crypto_encode/857x1723round/avx/encode.c	2020-08-31 19:56:55.599748407 -0400
+++ supercop-20200826-patched/crypto_encode/857x1723round/avx/encode.c	2020-08-31 20:09:19.807727175 -0400
@@ -19,6 +19,7 @@
   uint16 *writing;
   uint16 r0,r1;
   uint32 r2;
+  uint32 s0;
   
   reading = (uint16 *) R0;
   writing = R;
@@ -47,13 +48,20 @@
       ));
     x = _mm256_permute4x64_epi64(x,0xd8);
     _mm_storeu_si128((__m128i *) writing,_mm256_extractf128_si256(x,0));
-    *((uint32 *) (out+0)) = _mm256_extract_epi32(x,4);
-    *((uint32 *) (out+4)) = _mm256_extract_epi32(x,6);
+    s0 = (uint32) _mm256_extract_epi32(x,4);
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0;
+    s0 = (uint32) _mm256_extract_epi32(x,6);
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0;
     reading += 16;
     writing += 8;
-    out += 8;
   }
-  R[428] = (((3*((10923*R0[856]+16384)>>15)+2583)&16383)*10923)>>15;
+  R[428] = (uint16) ((((3*((10923*R0[856]+16384)>>15)+2583)&16383)*10923)>>15);
   
   reading = (uint16 *) R;
   writing = R;
@@ -137,13 +145,13 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)65;
-    R[i] = r2;
+    R[i] = (uint16) r2;
   }
   r0 = R[106];
   r1 = R[107];
   r2 = r0+r1*(uint32)65;
-  *out++ = r2; r2 >>= 8;
-  R[53] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[53] = (uint16) r2;
   
   reading = (uint16 *) R;
   writing = R;
@@ -185,8 +193,8 @@
   r0 = R[52];
   r1 = R[53];
   r2 = r0+r1*(uint32)4225;
-  *out++ = r2; r2 >>= 8;
-  R[26] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[26] = (uint16) r2;
   
   reading = (uint16 *) R;
   writing = R;
@@ -210,11 +218,18 @@
       ));
     x = _mm256_permute4x64_epi64(x,0xd8);
     _mm_storeu_si128((__m128i *) writing,_mm256_extractf128_si256(x,0));
-    *((uint32 *) (out+0)) = _mm256_extract_epi32(x,4);
-    *((uint32 *) (out+4)) = _mm256_extract_epi32(x,6);
+    s0 = (uint32) _mm256_extract_epi32(x,4);
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0;
+    s0 = (uint32) _mm256_extract_epi32(x,6);
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0; s0 >>= 8;
+    *out++ = (unsigned char) s0;
     reading += 16;
     writing += 8;
-    out += 8;
   }
   R[13] = R[26];
   
@@ -222,16 +237,16 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)292;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   for (i = 0;i < 3;++i) {
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)334;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[3] = R[6];
   
@@ -239,17 +254,17 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)436;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)743;
-  *out++ = r2; r2 >>= 8;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/857x1723round/ref/encode.c supercop-20200826-patched/crypto_encode/857x1723round/ref/encode.c
