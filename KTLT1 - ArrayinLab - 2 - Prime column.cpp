#include <iostream>
#include <vector>
#include <string>
using namespace std; 
bool isPrime(int n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true; 
}
int primeColumns(int arr[][1000], int row, int col) {
    bool check = false;
    int count = 0;
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += arr[i][j];
        }
        if (isPrime(sum)) {
            count++;
        }
    }
    return count;
}
int main () {
    int arr[][1000] = {{34,-15,11,-70,-23,24},{-39,-90,63,-45,-52,48},{-42,92,55,92,82,81}};
    cout << primeColumns(arr,3,6);
}