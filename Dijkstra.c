#include <stdio.h>
#define MAX 10
void dijkstra(int G[MAX][MAX], int n, int start, int dist[MAX]) {
    int vis[MAX] = {0};
    int i, j, u;
    for (i = 0; i < n; i++) dist[i] = -1;
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        int min = -1;
        for (j = 0; j < n; j++)
            if (!vis[j] && dist[j] != -1 && (min == -1 || dist[j] < min))
                min = dist[j], u = j;
        if (min == -1) break;
        vis[u] = 1;
        for (j = 0; j < n; j++)
            if (G[u][j] > 0 && !vis[j])
                if (dist[j] == -1 || dist[u] + G[u][j] < dist[j])
                    dist[j] = dist[u] + G[u][j];
    }
}
int main() {
    int G[MAX][MAX], dist[MAX];
    int n, start, i, j;
    printf("Vertices: ");
    scanf("%d", &n);
    printf("Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("Start: ");
    scanf("%d", &start);
    dijkstra(G, n, start, dist);
    printf("Node\tDist\n");
    for (i = 0; i < n; i++) {
        if (dist[i] == -1)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
    return 0;
}
/*### ✅ **Time Complexity Analysis**

**Algorithm:** Dijkstra's Algorithm (basic implementation using adjacency matrix)
**Input:**

* `n`: number of vertices
* `G[MAX][MAX]`: adjacency matrix

---

### 📘 **Main Operations in Code**

#### 1. **Outer loop (runs n−1 times):**

```c
for (i = 0; i < n - 1; i++)
```

#### 2. **Finding the minimum distance vertex (Linear search):**

```c
for (j = 0; j < n; j++) // O(n)
```

#### 3. **Relaxation step for all adjacent vertices:**

```c
for (j = 0; j < n; j++) // O(n)
```

---

### 📦 **Total Time Complexity**

* Outer loop: **O(n)**
* Inside that:

  * Finding min vertex: **O(n)**
  * Relaxing adjacent vertices: **O(n)**

So, total time:

> ✅ **Time Complexity = O(n²)**

---

### 🛠️ Note

This is a simple implementation using an adjacency matrix and linear search for the minimum vertex.
With a **min-heap + adjacency list**, Dijkstra’s algorithm can be optimized to:

> 🔹 **O((V + E) log V)** using a priority queue (heap-based Dijkstra)

Would you like the optimized version in C as well?
*/