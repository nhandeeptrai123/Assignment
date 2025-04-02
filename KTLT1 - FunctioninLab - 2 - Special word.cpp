#include <iostream>
using namespace std; 
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int sumDigit(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10; 
        n /= 10;
    }
    return sum;
}
bool isSpecialNumber(int n) {
    if (!isPrime(n)) {
        return 0;
    }
    if (!isPrime(sumDigit(n))) {
        return 0;
    }
    return 1;
}
int main () {
    int n;
cin >> n;
cout << isSpecialNumber(n);
}