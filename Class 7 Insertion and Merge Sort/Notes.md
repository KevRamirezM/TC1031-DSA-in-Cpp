## Insertion Sort

Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. The time complexity for this algorithm is O(n^2)


```cpp
void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i-1
        while (j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
```

The best case for this algorithm is when the array is already sorted (7 comparisons) O(n). Alternatively the worst case is 23 comparisons and the time complexity is O(n^2).

## Merge Sort

Merge sort is a divide-and-conquer algorithm that divides the input array into two halves and then merges the two sorted halves. This is a recursive algorithm.

---


1. Divide the array in half
2. Compare each element if its smaller
3. Sort each half recursively
4. Merge the two sorted halves into one sorted array

---

The array is divided in logbase2(n) splits. Divides the problem in smaller groups and then combines all of the results for the finished array. The time complexity for this algorithm is O(n log(n))
