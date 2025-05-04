#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int n, int profit[], int deadline[], int id[]) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (profit[j] < profit[j + 1]) {
                swap(&profit[j], &profit[j + 1]);
                swap(&deadline[j], &deadline[j + 1]);
                swap(&id[j], &id[j + 1]);
            }}
int get(int deadline[], int n) {
    int max = deadline[0];
    for (int i = 1; i < n; i++)
        if (deadline[i] > max)
            max = deadline[i];
    return max;
}
void func(int n, int profit[], int deadline[], int id[]) {
    sort(n, profit, deadline, id);
    int max = get(deadline, n);
    int seq[MAX];
    bool slot[MAX] = {false};
    int total = 0;
    for (int i = 0; i < max; i++)
        seq[i] = -1;
    for (int i = 0; i < n; i++) {
       for (int j = deadline[i] - 1; j >= 0; j--) {
            if (!slot[j]) {
                seq[j] = id[i];
                slot[j] = true;
                total += profit[i];
                break;
            }        }    }

    printf("Selected Job Sequence: ");
    for (int i = 0; i < max; i++)
        if (seq[i] != -1)
            printf("J%d ", seq[i]);
    printf("\nTotal Profit: %d\n", total);
}
int main() {
    int i, n;
    printf("Enter no. of jobs: ");
    scanf("%d", &n);
    int profit[MAX], deadline[MAX], id[MAX];
    printf("Enter job profits:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &profit[i]);
    printf("Enter job deadlines:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &deadline[i]);

    for (i = 0; i < n; i++)
        id[i] = i + 1;
    func(n, profit, deadline, id);
    return 0;
}
 

/*Here's the **step-by-step algorithm** for the **Job Sequencing Problem** implemented in your C program, using **Greedy Approach**:

---

### ? **Job Sequencing Algorithm**

**Input:**

* `n` jobs with:

  * `profit[i]`: profit of job `i`
  * `deadline[i]`: deadline of job `i`
* Only one job can be scheduled at a time slot.

**Output:**

* Job sequence that gives maximum total profit
* Total profit

---

### ?? **Step-by-step Algorithm**

1. **Input the number of jobs `n`**
   Read the profits and deadlines for each job.

2. **Assign Job IDs**
   For simplicity, assign job IDs from `1` to `n`.

3. **Sort Jobs by Profit (Descending)**
   Use Bubble Sort (inefficient, but used here)
   Sort based on `profit[i]`
   Rearrange `profit[]`, `deadline[]`, and `jobId[]` in sync.

4. **Find the Maximum Deadline (`maxDeadline`)**
   Iterate over `deadline[]` to get the largest deadline value.

5. **Initialize a Schedule Array**
   Create an array `schedule[maxDeadline]`, initialized to `-1` (means empty slot).

6. **Greedy Job Assignment**
   For each job in sorted list:

   * Try placing the job in the latest available slot = its deadline.
   * Start checking from `deadline[i] - 1` to `0`.
   * If an empty slot is found, assign the job, and add its profit to total.

7. **Print the Job Sequence**
   Print all assigned job IDs in the order of scheduled slots.

8. **Print Total Profit**

---

### ?? Example Pseudocode

```plaintext
jobSequencing(n, profit[], deadline[], jobId[]):
    sortJobsByProfitDescending(n, profit[], deadline[], jobId[])

    maxDeadline = findMaxDeadline(deadline[])
    schedule[] = array of size maxDeadline, initialized to -1

    totalProfit = 0

    for each job i from 0 to n-1:
        for j = deadline[i]-1 down to 0:
            if schedule[j] == -1:
                schedule[j] = jobId[i]
                totalProfit += profit[i]
                break

    print job sequence from schedule[]
    print totalProfit
```

---

Would you also like a time complexity analysis for this code?
*/