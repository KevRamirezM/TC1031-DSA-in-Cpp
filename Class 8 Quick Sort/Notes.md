## Quick Sort Algorithm

Quick sort is a divide-and-conquer algorithm that selects a 'pivot' element from the array and partitions the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

Picks a pivot, partitions the array and then recursively sorts the left and right part.

### How to select the pivot and do the partition?

- Hoare Classic: The first element is the pivot, two indices converge from opposite ends
- Lomuto Classic: The last element is the pivot, one index swaps from left to right
- Lomuto with pivot at the start: The first element is the pivot, one index swaps from left to right.

The worst case of the algorithm is when the Pivot is the biggest number.

---

### Code Implementation

```cpp
int partition(int a[], int lo, int hi){
    int pivot = a[lo];
    int i = lo + 1;
    for (int j = lo + 1; j <= hi; j++){
        if (a[j] < pivot){
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++
        }
    }
    int temp = a[lo]; a[lo] = a[i - 1]; a[i - 1] = temp;
}
```

```cpp
void quickSort(int a[], int lo, int hi){
    if (lo >= hi) return;
    int p = partition(a, lo, hi);
    quickSort(a, lo, p - 1);
    quickSort(a, p + 1, hi;
}
```

---

### Best and worst cases
- In the worst case the partition is unbalance, the minor element is the pivot and every partition splits off just one element. O(n^2)

- In the best case the partition is already balance, we assume that we always pick the middle element. O(n log(n))

- Quicksort is not stable and it is an in place algorithm.

---

Inside quicksorts partition it only swaps elements inside the array itself, it doesnt have a temporary array so it uses less memory than MergeSort.

The real efficiency of the Quicksort algorithm comes from choosing the right pivot. One of the ways to pick it is tgetting the median of the three elements which are the first, middle and last. Whenever the split is 25/75 the time complexity is close to O(n log(n))
