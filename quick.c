#include <stdio.h>

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Swap if the element is smaller than pivot
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap pivot into correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Quick Sort Function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
/*Here’s the **step-by-step time complexity analysis** for your **Quick Sort** implementation:

---

### 🔹 **1. Function: `partition(arr, low, high)`**

This function does the following:

* Chooses the **last element as pivot**.
* Iterates from `low` to `high-1`:

  * If `arr[j] < pivot`, swaps `arr[j]` with `arr[i+1]`.
* Finally, places the pivot at the correct position.

🕒 **Time Complexity**:

* One full pass through the array segment → **`O(n)`** where `n = high - low + 1`.

---

### 🔹 **2. Function: `quickSort(arr, low, high)`**

This function is **recursive**:

* Picks a pivot using `partition()`.
* Recursively sorts:

  * Left side: `quickSort(arr, low, pi - 1)`
  * Right side: `quickSort(arr, pi + 1, high)`

---

### 🔹 **3. Overall Time Complexity (T(n))**

Let’s break it down:

#### ✅ **Best & Average Case**:

* Pivot divides array roughly in half each time.
* Recursion depth: `log n`
* Work per level: `O(n)` (due to partition)

🧮 So:

```
T(n) = O(n log n)
```

#### ❌ **Worst Case** (Already sorted / All elements same):

* Pivot ends up at one end → unbalanced partition.
* Recursion depth: `O(n)`
* Work per level: `O(n)`

🧮 So:

```
T(n) = O(n^2)
```

---

### 🔹 **Final Answer**

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | `O(n log n)`    |
| Average Case | `O(n log n)`    |
| Worst Case   | `O(n²)`         |

---

### 🔹 **Space Complexity (Bonus)**

* **In-place sorting**, so no extra array → **O(1) auxiliary space**
* But **recursion stack** in worst case → O(n)

🧠 So,

* **Average case space**: `O(log n)`
* **Worst case space**: `O(n)`

---

Would you like a dry-run example to better visualize how Quick Sort works step by step?
*/