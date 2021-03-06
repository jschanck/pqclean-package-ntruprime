--- supercop-20200826/crypto_core/wforcesntrup761/ref/wforce.c
+++ supercop-20200826-patched/crypto_core/wforcesntrup761/ref/wforce.c
@@ -16,11 +16,11 @@
 /* return -1 if x!=0; else return 0 */
 static int int16_nonzero_mask(int16 x)
 {
-  uint16 u = x; /* 0, else 1...65535 */
+  uint16 u = (uint16) x; /* 0, else 1...65535 */
   uint32 v = u; /* 0, else 1...65535 */
-  v = -v; /* 0, else 2^32-65535...2^32-1 */
+  v = ~v+1; /* 0, else 2^32-65535...2^32-1 */
   v >>= 31; /* 0, else 1 */
-  return -v; /* 0, else -1 */
+  return -(int) v; /* 0, else -1 */
 }
 
 /* 0 if Weightw_is(r), else -1 */
@@ -30,7 +30,7 @@
   int i;
 
   for (i = 0;i < p;++i) weight += r[i]&1;
-  return int16_nonzero_mask(weight-w);
+  return int16_nonzero_mask((int16) (weight-w));
 }
 
 /* out = in if bottom bits of in have weight w */
@@ -42,7 +42,7 @@
   int i,mask;
 
   mask = Weightw_mask(in); /* 0 if weight w, else -1 */
-  for (i = 0;i < w;++i) out[i] = ((in[i]^1)&~mask)^1;
-  for (i = w;i < p;++i) out[i] = in[i]&~mask;
+  for (i = 0;i < w;++i) out[i] = (small) (((in[i]^1)&~mask)^1);
+  for (i = w;i < p;++i) out[i] = (small) (in[i]&~mask);
   return 0;
 }

