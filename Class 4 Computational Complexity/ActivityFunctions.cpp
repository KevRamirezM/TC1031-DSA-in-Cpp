// Activity 1.1 Iterative, Recursive Functions and their Complexity Analysis
// A00844255
// 24-08-2026

#include <iostream>
using namespace std;

// First function is given by O(n) time complexity
int iterativeSum(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

// This next function is given by O(n) time complexity
int recursiveSum(int n){
    if(n == 0){
        return 0;
    }
    return n + recursiveSum(n - 1);
}

// The last function is given by O(1) time complexity
int directSum(int n){
    return (n * (n + 1)) / 2;
}

int main(){
    int num;
    cout << "Choose an opcion" << endl;
    cout << "1 iterativeSum" << endl;
    cout << "2 recursiveSum" << endl;
    cout << "3 directSum" << endl;
    cout << "4 all of them" << endl;
    cin >> num;
    switch(num){
        case 1:{
            int number;
            int result;
            cout << "Insert a number ";
            cin >> number;
            if (number>=0){
                result = iterativeSum(number);
                cout << "Result " << result;
            }
            else{
                cout << "Negative number is not valid";
            }
        break;
        }
        case 2:{
            int number;
            int result;
            cout << "Insert a number ";
            cin >> number;
            if (number>=0){
                result = recursiveSum(number);
                cout << "Result " << result;
            }
            else{
                cout << "Negative number is not valid";
            }
        break;
        }
        case 3:{
            int number;
            int result;
            cout << "Insert a number ";
            cin >> number;
            if (number>=0){
                result = directSum(number);
                cout << "Result " << result << endl;
            }
            else{
                cout << "Negative number is not valid";
            }
        break;
        }
        case 4:{
            int number;
            int result1;
            int result2;
            int result3;
            cout << "Insert a number ";
            cin >> number;
            if (number>=0){
                result1 = iterativeSum(number);
                cout << "Result of iterativeSum: " << result1 << endl;
                result2 = recursiveSum(number);
                cout << "Result of recursiveSum: " << result2 << endl;
                result3 = directSum(number);
                cout << "Result of directSum: " << result3 << endl;
            }
            else{
                cout << "Negative number is not valid";
            }
        break;
        }
        default:{
            cout << "Invalid request";
            break;
        }
    }
}