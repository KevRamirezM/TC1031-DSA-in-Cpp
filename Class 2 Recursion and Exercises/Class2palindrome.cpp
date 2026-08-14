#include <iostream>

bool palindrome(const char str[], int i, int f){
    if (i>=f){
        return true;
    }
    else if(str[i] == str[f]){
        return palindrome(str, i+1, f-1);
    }
    else{
        return false;
    }
}

int main(){
    bool res = palindrome("racecar", 0, 6);
    std::cout << "Palindrome " << res << " (1=True, 0=False)" << std::endl;
}