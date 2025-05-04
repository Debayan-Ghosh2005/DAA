#include <stdio.h>
#include <stdlib.h>
#define INF 1000000
int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    int from[E], to[E], weight[E];
    printf("Enter each edge in format: from to weight\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &from[i], &to[i], &weight[i]);
    }
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[source] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[from[j]] != INF && dist[from[j]] + weight[j] < dist[to[j]]) {
                dist[to[j]] = dist[from[j]] + weight[j];
            }
        }
    }
    for (int j = 0; j < E; j++) {
        if (dist[from[j]] != INF && dist[from[j]] + weight[j] < dist[to[j]]) {
            printf("Graph contains negative weight cycle\n");
            return 0;
        }    
}
    printf("\nVertex\tDistance from Source %d\n", source);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
    return 0;
}
/*### ✅ **Time Complexity of Bellman-Ford Algorithm (Given Code)**

---

### 📘 **Key Variables**

* `V` = Number of vertices
* `E` = Number of edges

---

### 🔍 **Main Loops**

#### 1. **Relaxation Loop (V−1 times)**

```c
for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
        // Relax edge
    }
}
```

* Outer loop: **O(V)**
* Inner loop: **O(E)**
* Total: **O(V × E)**

---

#### 2. **Negative Cycle Check (Single pass over all edges)**

```c
for (int j = 0; j < E; j++) {
    // Check for negative cycle
}
```

* Complexity: **O(E)**

---

### ✅ **Total Time Complexity**

> 🔹 **O(V × E)**

---

### ⚠️ Note

This is the **standard time complexity** of the Bellman-Ford algorithm, optimal for graphs with negative weights and suitable for **sparse graphs**.

Would you like a comparison with Dijkstra's algorithm?
*/