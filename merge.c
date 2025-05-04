#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int leftArr[n1], rightArr[n2]; // Temporary arrays

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; // Initial indices

    // Merge the temp arrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Avoids overflow

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    // Taking user input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking user input for array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Calling Merge Sort function
    mergeSort(arr, 0, n - 1);

    // Displaying sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
/*Here's the **step-by-step time complexity analysis** of the given Merge Sort code:

---

### 🔹 **1. Function: `mergeSort(arr, left, right)`**

This function divides the array recursively:

* At each level, the array is **divided into two halves**:

  * First half: `mergeSort(arr, left, mid)`
  * Second half: `mergeSort(arr, mid+1, right)`
* This continues **until each subarray has one element** (base case: `left >= right`).

🕒 **Time complexity of divide step**:

* Constant time `O(1)` (just computing `mid`).

🔁 **Number of levels (depth of recursion)**:

* The array is divided in half each time → log₂(n) levels → **`O(log n)`**

---

### 🔹 **2. Function: `merge(arr, left, mid, right)`**

This function merges two sorted arrays of sizes `n1` and `n2`:

* Copying into temp arrays:

  * Takes `O(n1 + n2)` time
* Merging step:

  * Also takes `O(n1 + n2)` time

✅ So, merging two halves of total size `n` takes **`O(n)`** time.

---

### 🔹 **3. Putting It All Together**

Let’s analyze total time `T(n)` to sort an array of size `n`:

* At each level:

  * `mergeSort()` divides array → 2 calls
  * `merge()` merges back → cost is `O(n)`
* Number of levels = `log n`

🧮 So the total time is:

```
T(n) = O(n) + O(n) + O(n) + ... (log n times)
     = O(n log n)
```

---

### 🔹 **Final Answer**

✅ **Time Complexity: `O(n log n)`**

---

### 🔹 **Space Complexity (Bonus)**

* Temporary arrays `leftArr[]` and `rightArr[]` → O(n)
* Recursion stack → O(log n)

🧠 So, **Auxiliary Space: `O(n)`**

---

Would you like a diagram showing how the recursive calls and merges happen?
*/
