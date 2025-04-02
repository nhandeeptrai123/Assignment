#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(const char* str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
            break;
        }
        left++;
        right--;
    }
return 1;
}
int main () {
    const char* str = "zaa";
cout << isPalindrome(str);
}