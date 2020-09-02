--- supercop-20200826/crypto_sort/int32/x86/sort.c
+++ supercop-20200826-patched/crypto_sort/int32/x86/sort.c
@@ -1,8 +1,18 @@
-#include "crypto_sort.h"
-#include "crypto_int32.h"
-#define int32 crypto_int32
+#include "crypto_sort_int32.h"
 
-#include "int32_minmax_x86.inc"
+#include <stdint.h>
+#define int32 int32_t
+
+#define int32_MINMAX(a,b) \
+do { \
+  int32_t ab = (b) ^ (a); \
+  int32_t c = (int32_t)((int64_t)(b) - (int64_t)(a)); \
+  c ^= ab & (c ^ (b)); \
+  c >>= 31; \
+  c &= ab; \
+  (a) ^= c; \
+  (b) ^= c; \
+} while(0)
 
 /* assume 2 <= n <= 0x40000000 */
 static void crypto_sort_smallindices(int32 *x,int32 n)
@@ -87,23 +97,27 @@
     i = 0;
     j = 0;
     for (q = top;q > p;q >>= 1) {
-      if (j != i) for (;;) {
-        if (j == n - q) goto done;
-        int32 a = x[j + p];
-        for (r = q;r > p;r >>= 1)
-          int32_MINMAX(a,x[j + r]);
-        x[j + p] = a;
-        ++j;
-        if (j == i + p) {
-          i += 2 * p;
-          break;
+      if (j != i) {
+        for (;;) {
+          if (j == n - q) goto done;
+          int32 a = x[j + p];
+          for (r = q;r > p;r >>= 1) {
+            int32_MINMAX(a,x[j + r]);
+          }
+          x[j + p] = a;
+          ++j;
+          if (j == i + p) {
+            i += 2 * p;
+            break;
+          }
         }
       }
       while (i + p <= n - q) {
         for (j = i;j < i + p;++j) {
           int32 a = x[j + p];
-          for (r = q;r > p;r >>= 1)
+          for (r = q;r > p;r >>= 1) {
             int32_MINMAX(a,x[j+r]);
+          }
           x[j + p] = a;
         }
         i += 2 * p;
@@ -112,8 +126,9 @@
       j = i;
       while (j < n - q) {
         int32 a = x[j + p];
-        for (r = q;r > p;r >>= 1)
+        for (r = q;r > p;r >>= 1) {
           int32_MINMAX(a,x[j+r]);
+        }
         x[j + p] = a;
         ++j;
       }
diff -ru --no-dereference supercop-20200826/crypto_sort/uint32/useint32/sort.c supercop-20200826-patched/crypto_sort/uint32/useint32/sort.c
