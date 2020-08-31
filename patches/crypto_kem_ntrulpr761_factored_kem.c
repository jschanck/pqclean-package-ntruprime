--- supercop-20200826/crypto_kem/ntrulpr761/factored/kem.c	2020-08-31 09:55:07.109787727 -0400
+++ supercop-20200826-patched/crypto_kem/ntrulpr761/factored/kem.c	2020-08-31 07:55:50.475704049 -0400
@@ -110,12 +110,25 @@
 
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
   uint32 L[p];
+  int i;
 
-  randombytes((unsigned char *) L,sizeof L);
-  crypto_decode_pxint32(L,(unsigned char *) L);
+  for (i = 0;i < p;++i) L[i] = urandom32();
   Short_fromlist(out,L);
 }
 
diff -ru --no-dereference supercop-20200826/crypto_kem/sntrup761/factored/kem.c supercop-20200826-patched/crypto_kem/sntrup761/factored/kem.c
