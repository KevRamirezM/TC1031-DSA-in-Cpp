using namespace std;
#include <iostream>
#include "binarySearch.h"

int main(){
    vector<int> data = {3, 7, 11, 15, 19, 23, 29, 31, 37, 41, 47};
    int target = 47;
    int targetPos;

    cout << "Target is located in: " <<endl;

    targetPos = binarySearch(data, target);
}