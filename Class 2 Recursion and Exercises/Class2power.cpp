#include <iostream>

long power(int base, int n){
    if (n == 0) {
        return 1;
    }
    else{
        return base * power(base, n-1);
    }
}

int main(){
    long res;
    res = power(6, 2);
    std::cout << "Exponente " << res << std::endl;
}