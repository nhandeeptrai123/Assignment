#include <iostream>
using namespace std;
int findLength (char str[]) {
    int index = 0;
    while (str[index]!='\0') {
        index++; 
    }
    int length = index;
    return length;
}
int find(char str[], char substr[]) {
    int position = -1;
    size_t lenStr = findLength(str);
    size_t lensubStr = findLength(substr);
    if (lenStr == 0 || lenStr < lensubStr) {
        return -1;
    }
    for (int i = 0; i < lenStr; i++) {
        size_t j;
        for (j = 0; j < lensubStr; j++) {
            if (str[i+j] != substr[j]) {
                break;
            }
        }
        if (j == lensubStr) {
            return i;
        }
    }
    return -1;
}
int main () {
char str[] = "hello world";
char substr[] = "world";
cout << find(str, substr);
}