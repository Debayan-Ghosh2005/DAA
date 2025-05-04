#include <stdio.h>
#define SIZE 50
int d[SIZE], m[SIZE][SIZE], s[SIZE][SIZE];
void matrix_chain_order(int len, int p[]) {
    int i, j, k, l, n = len - 1, q;
    for (i = 1; i <= n; i++) m[i][i] = 0;
    for (l = 2; l <= n; l++)
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1; m[i][j] = 1e9;
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) { m[i][j] = q; s[i][j] = k; }
            }        }
    printf("\nCost of multiplication = %d\n", m[1][n]);
}
void print_optimal(int i, int j) {
    if (i == j) printf("A[%d] ", i);
    else { printf("( "); print_optimal(i, s[i][j]); print_optimal(s[i][j]+1, j); printf(") "); }
}
int main() {
    int n, i, j;
    printf("Enter number of dimensions: ");
    scanf("%d", &n);
    printf("Enter dimension sequence: ");
    for (i = 0; i < n; i++) scanf("%d", &d[i]);
    matrix_chain_order(n, d);
    printf("Optimal Parenthesization: "); print_optimal(1, n - 1); printf("\n\n");
    printf("Cost Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < i; j++) printf("\t");
        for (j = i; j < n; j++) printf("%5d\t", m[i][j]);
        printf("\n");
    }
    printf("\nSequence Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j <= i; j++) printf("\t");
        for (j = i + 1; j < n; j++) printf("%5d\t", s[i][j]);
        printf("\n");
    }
    return 0;
}
/*### ✅ **Time Complexity Analysis**

**Program:** Matrix Chain Multiplication using Dynamic Programming (Tabulation)
**Goal:** Find minimum number of scalar multiplications needed to multiply a chain of matrices.

---

### 🔍 **Variables**

* `d`: number of dimensions = number of matrices + 1
* `n = d - 1`: number of matrices

---

### 📘 **Key Steps in the Code**

#### 1. **Initialization:**

```c
for(i = 1; i <= n; i++) {
    m[i][i] = 0;
}
```

* Time: **O(n)**

#### 2. **Main Dynamic Programming Logic:**

```c
for(l = 2; l <= n; l++) {                 // O(n)
    for(i = 1; i <= n - l + 1; i++) {     // O(n)
        j = i + l - 1;
        for(k = i; k <= j - 1; k++) {     // O(n)
            q = m[i][k] + m[k+1][j] + (dim[i-1]*dim[j]*dim[k]);
            if(q < m[i][j]) {
                m[i][j] = q;
                s[i][j] = k;
            }
        }
    }
}
```

* This is a **triple nested loop**.
* Each loop can run up to `n` times.
* So total time = **O(n³)**

---

### 📦 **Total Time Complexity:**

> ✅ **Time Complexity = O(n³)**

Where `n` is the number of matrices = `d - 1`.

---

Let me know if you'd like a space or auxiliary complexity explanation as well.
*/