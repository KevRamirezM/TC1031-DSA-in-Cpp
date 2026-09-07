using namespace std;
#include <vector>

template <typename T>

int binarySearch(const vector<T> &data, const T &target){
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) {
            return mid;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}