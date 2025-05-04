# include<stdio.h>
#define MAX 50
void sort(int weights[], int vals[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(vals[j]*weights[j+1] < vals[j+1]*weights[j]){
                int temp1=weights[j];
                int temp2=vals[j];
                weights[j]=weights[j+1];
                vals[j]=vals[j+1];
                weights[j+1]=temp1;
                vals[j+1]=temp2;
            }
        }
    }
}

int knapsack(int x, int weights[], int vals[], int n){
    sort(weights, vals, n);
    int totalvals = 0;
    int i;
    for(i=0;i<n;i++){
        if(x >= weights[i])
        {
            x -= weights[i];
            totalvals += vals[i];
            
        }
        else
        {
            totalvals += ((float)vals[i] * x) / weights[i]; 
            break;
        }
    }
    return totalvals;
}
int main(){
    int weights[MAX], vals[MAX],x,i,n;
    printf("\n enter the number of elements:");
    scanf("%d",&n);
    printf("\n enter the weights:");
    for(i=0;i<n;i++){
        printf("\n Weights:");
        scanf("%d",&weights[i]);
    }
    printf("\n enter the vals:");
    for(i=0;i<n;i++){
        printf("\n Values:");
        scanf("%d",&vals[i]);
    }
    printf("\n value and weight ratio:");
    for(i=0;i<n;i++){
        float ratio = (float)vals[i]/weights[i];
        printf("ratio: %.2f\n",ratio);
    }
    printf("\n enter  the capacity:");
    scanf("%d",&x);
    float maxval = knapsack(x, weights, vals, n);
    printf("max value : %.2f\n", maxval);
    
    return 0;
}


/*Here's a **step-by-step time complexity analysis** for your **Fractional Knapsack** C program:

---

### ✅ **1. `sortItems()` Function**

This function sorts items based on **value-to-weight ratio** using **Bubble Sort**.

* Two nested loops:

  ```c
  for (i = 0; i < n - 1; i++)
      for (j = 0; j < n - i - 1; j++)
  ```

* For each pair, ratio is computed → constant time

📌 **Time Complexity** of sorting:
🔸 Worst-case: **O(n²)**
(uses bubble sort — inefficient for large `n`)

---

### ✅ **2. `fractionalKnapsack()` Function**

This part processes items in a loop:

```c
for (i = 0; i < n; i++) {
   ...
}
```

* Each item is either fully or fractionally taken
* At most **n** items are processed

📌 **Time Complexity** of this loop: **O(n)**

---

### ✅ **3. Total Time Complexity**

| Step                 | Time Complexity     |
| -------------------- | ------------------- |
| Sorting by ratio     | O(n²) (Bubble sort) |
| Filling the knapsack | O(n)                |
| **Total**            | **O(n²)**           |

🔁 **So the overall time complexity is:**

```
O(n²)    → due to bubble sort
```

---

### ✅ **Can it be improved?**

Yes. If you use a more efficient sorting algorithm like **Merge Sort** or **Quick Sort**, sorting becomes:

* **O(n log n)**

Then total time becomes:

```
O(n log n) + O(n) = O(n log n)
```

---

### ✅ **Space Complexity**

* `solution[]` array → O(n)
* No recursion → no extra stack space

📌 **Auxiliary Space**: **O(n)**

---

Would you like a version using `struct` for better readability and sorting?
*/