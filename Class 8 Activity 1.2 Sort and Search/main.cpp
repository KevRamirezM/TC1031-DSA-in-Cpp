#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort
// Time Complexity: O(n^2)
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
// Time Complexity: O(n^2)
template <typename T>
void selectionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Insertion Sort
// Time Complexity: O(n^2)
template <typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Sequential Search
// Time Complexity: O(n)
template <typename T>
int sequentialSearch(const vector<T>& arr, const T& target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search
// Time Complexity: O(log n)
template <typename T>
int binarySearch(const vector<T>& arr, const T& target) {
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> numbers = {29, 10, 14, 37, 10, 5, 22, 18};
    vector<int> bubble = numbers;
    vector<int> selection = numbers;
    vector<int> insertion = numbers;

    bubbleSort(bubble);
    selectionSort(selection);
    insertionSort(insertion);

    cout << "Bubble Sort: ";
    for (int x : bubble) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Selection Sort: ";
    for (int x : selection) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Insertion Sort: ";
    for (int x : insertion) {
        cout << x << " ";
    }
    cout << endl;

    int target = 22;
    cout << "Sequential Search: " << sequentialSearch(bubble, target) << endl;
    cout << "Binary Search: " << binarySearch(bubble, target) << endl;
    return 0;
}