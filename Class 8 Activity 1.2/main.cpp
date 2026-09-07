#include <iostream>
#include <vector>
using namespace std;

// BubbleSort
template <typename T>
int bubbleSort(vector<T>& arr) {
    int n = arr.size();
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}

int main() {
    vector<int> arr = {5, 3, 1, 12, 9};

    int comparisons = bubbleSort(arr);

    cout << "Vector: ";
    for (int x : arr) {
        cout << x << " ";
    }

    cout << "\nComparisons: " << comparisons << endl;

    return 0;
}

// SelectionSort
template <typename T>
int selectionSort(vector<T>& arr) {
    int n = arr.size();
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
    return comparisons;
}

// InsertionSort

template <typename T>
void insertionSort(T a[], T n){
    for (T i = 1; i < n; i++){
        T key = a[i];
        T j = i-1;
        while (j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// SequentialSearch
template <typename T>
int sequentialSearch(vector<T> & arr, int target){
    for (T i = 0; i < arr.size(); i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

// binarySearch
template <typename T>
int binarySearch(vector<T> a, int target){
    int lo = 0;
    int hi = (a.size() - 1);
    while(int lo <= int hi){
        int mid = ((lo + hi) / 2);
        if (a[mid] == target){
            return mid;
        }
        if (a[mid] > target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return -1;
}