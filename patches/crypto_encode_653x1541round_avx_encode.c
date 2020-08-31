--- supercop-20200826/crypto_encode/653x1541round/avx/encode.c	2020-08-31 19:56:55.579748076 -0400
+++ supercop-20200826-patched/crypto_encode/653x1541round/avx/encode.c	2020-08-31 20:09:19.783727004 -0400
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
-  R[326] = (((3*((10923*R0[652]+16384)>>15)+2310)&16383)*10923)>>15;
+  R[326] = (uint16) ((((3*((10923*R0[652]+16384)>>15)+2310)&16383)*10923)>>15);
   
   reading = (uint16 *) R;
   writing = R;
@@ -116,11 +124,18 @@
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
   
   reading = (uint16 *) R;
@@ -183,11 +198,18 @@
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
   R[20] = R[40];
   
@@ -195,8 +217,8 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)1887;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[10] = R[20];
   
@@ -204,9 +226,9 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)13910;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   R[5] = R[10];
   
@@ -214,30 +236,30 @@
     r0 = R[2*i];
     r1 = R[2*i+1];
     r2 = r0+r1*(uint32)2953;
-    *out++ = r2; r2 >>= 8;
-    *out++ = r2; r2 >>= 8;
-    R[i] = r2;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    *out++ = (unsigned char) r2; r2 >>= 8;
+    R[i] = (uint16) r2;
   }
   r0 = R[4];
   r1 = R[5];
   r2 = r0+r1*(uint32)2953;
-  *out++ = r2; r2 >>= 8;
-  R[2] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[2] = (uint16) r2;
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)134;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   R[1] = R[2];
   
   r0 = R[0];
   r1 = R[1];
   r2 = r0+r1*(uint32)71;
-  *out++ = r2; r2 >>= 8;
-  R[0] = r2;
+  *out++ = (unsigned char) r2; r2 >>= 8;
+  R[0] = (uint16) r2;
   
   r0 = R[0];
-  *out++ = r0; r0 >>= 8;
-  *out++ = r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; r0 >>= 8;
+  *out++ = (unsigned char) r0; /*clang-analyzer-deadcode.DeadStores*/ /*r0 >>= 8;*/
 }
diff -ru --no-dereference supercop-20200826/crypto_encode/653x1541round/ref/encode.c supercop-20200826-patched/crypto_encode/653x1541round/ref/encode.c
