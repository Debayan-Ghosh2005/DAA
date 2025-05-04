#include<stdio.h>
#include<stdlib.h>
#define inf 99999
int mincost=0,g[20][20],visited[20];
int prims(int n)
{
	int min,i,j,k,v1,v2;
	for(i=1;i<=n;i++)
	visited[i]=0;
		visited[1]=1;
		for(k=1;k<=n-1;k++){
		min=inf;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(g[i][j]!=inf && (visited[i]==1&&visited[j]==0))
				{
					if(g[i][j]<min){
						min=g[i][j];
						v1=i;
						v2=j;
					}
				}
				
			}
		}
		visited[v1]=visited[v2]=1;
		mincost+=min;
		printf("\nEdge %d=%d---%d",k,v1,v2);
	}
	return mincost;
}
void display(int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		printf("%d\t",g[i][j]);
		printf("\n");
	}
}
int main(){
	int n,i,j;
	printf("\n enter the number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	     for(j=1;j<=n;j++){
	     	printf("\n enter weight of edge %d----%d",i,j);
	     	scanf("%d",&g[i][j]);
	     	if(g[i][j] == 0)
	     	g[i][j] == inf;
	     }
	}
	printf("\n\n");
	display(n);
	printf("\nmincost=%d",prims(n));
}
/*### ? **Time Complexity Analysis**

**Program:** Prim’s Algorithm (Simple Implementation using Adjacency Matrix)
**Goal:** Find the **Minimum Spanning Tree (MST)** of a weighted graph.

---

### ?? **Key Variables**

* `n`: Number of vertices
* `g[20][20]`: Adjacency matrix
* `visited[20]`: Marks if a vertex is included in MST

---

### ?? **Key Parts of the Code**

#### 1. **Outer loop:**

```c
for(k = 1; k <= n - 1; k++) {  // Runs (n - 1) times
```

#### 2. **Nested loops to find the minimum edge:**

```c
for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
        if (g[i][j] != inf && visited[i] == 1 && visited[j] == 0) {
            if(g[i][j] < min) {
                min = g[i][j];
                v1 = i;
                v2 = j;
            }
        }
    }
}
```

* This nested loop runs in **O(n²)** time for each outer iteration.

---

### ?? **Total Time Complexity**

* Outer loop runs **(n - 1)** times
* Each iteration of the outer loop runs **O(n²)**

> ? **Time Complexity = O(n³)**

---

### ?? Note

This is a **basic version** of Prim's algorithm using an adjacency matrix and simple linear search.
With better data structures (like min-heaps and adjacency lists), Prim’s algorithm can be optimized to **O(E log V)** using a priority queue.

Let me know if you want the optimized version too.
*/




