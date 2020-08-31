--- supercop-20200826/crypto_kem/sntrup761/factored/kem.c	2020-08-31 09:55:07.113787676 -0400
+++ supercop-20200826-patched/crypto_kem/sntrup761/factored/kem.c	2020-08-31 07:59:03.241787632 -0400
@@ -80,13 +80,25 @@
 
 /* ----- higher-level randomness */
 
+static uint32 urandom32(void)
+{
+  unsigned char c[4];
+  uint32 out[4];
+
+  randombytes(c,4);
+  out[0] = (uint32)c[0];
+  out[1] = ((uint32)c[1])<<8;
+  out[2] = ((uint32)c[2])<<16;
+  out[3] = ((uint32)c[3])<<24;
+  return out[0]+out[1]+out[2]+out[3];
+}
+
 static void Short_random(small *out)
 {
   uint32 L[ppadsort];
   int i;
 
-  randombytes((unsigned char *) L,4*p);
-  crypto_decode_pxint32(L,(unsigned char *) L);
+  for (i = 0;i < ppadsort;++i) L[i] = urandom32();
   for (i = 0;i < w;++i) L[i] = L[i]&(uint32)-2;
   for (i = w;i < p;++i) L[i] = (L[i]&(uint32)-3)|1;
   for (i = p;i < ppadsort;++i) L[i] = 0xffffffff;
@@ -99,8 +111,7 @@
   uint32 L[p];
   int i;
 
-  randombytes((unsigned char *) L,sizeof L);
-  crypto_decode_pxint32(L,(unsigned char *) L);
+  for (i = 0;i < p;++i) L[i] = urandom32();
   for (i = 0;i < p;++i) out[i] = (((L[i]&0x3fffffff)*3)>>30)-1;
 }
 
diff -ru --no-dereference supercop-20200826/crypto_kem/sntrup761/factored/params.h supercop-20200826-patched/crypto_kem/sntrup761/factored/params.h
