#include <stdio.h>

// Structure to store both max and min
struct Result {
    int max;
    int min;
};

// Function to find max and min using divide and conquer
struct Result findMaxMin(int arr[], int low, int high) {
    struct Result res, leftRes, rightRes;

    // If only one element
    if (low == high) {
        res.max = arr[low];
        res.min = arr[low];
        return res;
    }

    // If two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            res.max = arr[low];
            res.min = arr[high];
        } else {
            res.max = arr[high];
            res.min = arr[low];
        }
        return res;
    }

    // If more than two elements
    int mid = (low + high) / 2;
    leftRes = findMaxMin(arr, low, mid);
    rightRes = findMaxMin(arr, mid + 1, high);

    // Compare results of both halves
    res.max = (leftRes.max > rightRes.max) ? leftRes.max : rightRes.max;
    res.min = (leftRes.min < rightRes.min) ? leftRes.min : rightRes.min;

    return res;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Result ans = findMaxMin(arr, 0, n - 1);

    printf("Maximum element: %d\n", ans.max);
    printf("Minimum element: %d\n", ans.min);

    return 0;
}
/*Here’s the **step-by-step time complexity analysis** for the **Max-Min Problem using Divide and Conquer** (your code):

---

### 🔹 **1. Base Cases in `findMaxMin()`**

* **Case 1**: If only one element
  → Directly assign max and min → **O(1)**

* **Case 2**: If two elements
  → One comparison to determine max and min → **O(1)**

These are **constant-time operations**.

---

### 🔹 **2. Recursive Case (More than Two Elements)**

* The array is **divided into two halves**:

  ```c
  mid = (low + high) / 2;
  leftRes = findMaxMin(arr, low, mid);
  rightRes = findMaxMin(arr, mid + 1, high);
  ```

* Then compare the **max and min from both halves** using:

  ```c
  res.max = (leftRes.max > rightRes.max) ? leftRes.max : rightRes.max;
  res.min = (leftRes.min < rightRes.min) ? leftRes.min : rightRes.min;
  ```

  → This comparison is **O(1)**

🧮 So for `n` elements:

```
T(n) = 2T(n/2) + O(1)
```

---

### 🔹 **3. Solving the Recurrence**

The recurrence relation is:

```
T(n) = 2T(n/2) + C
```

This is a standard divide and conquer recurrence, and it solves to:

```
T(n) = O(n)
```

🔁 Why?

* At each level, we do constant extra work.
* Total number of levels in recursion = log₂(n)
* Total work across all levels = O(n)

---

### 🔹 **Total Comparisons (Extra Insight)**

* For `n` elements, this method requires approximately:

```
⟶ 3n/2 - 2 comparisons (better than naive 2n - 2)
```

✅ So, it’s an **optimized linear-time** approach for finding both max and min.

---

### 🔹 **Final Time Complexity**

| Case      | Time Complexity |
| --------- | --------------- |
| All cases | **`O(n)`**      |

---

### 🔹 **Space Complexity**

* **No extra arrays** → O(1)
* **Recursion stack** → Depth is `O(log n)`

✅ **Auxiliary Space: `O(log n)`**

---

Would you like a visualization or dry run of this algorithm on a sample input (e.g., 5 elements)?
*/