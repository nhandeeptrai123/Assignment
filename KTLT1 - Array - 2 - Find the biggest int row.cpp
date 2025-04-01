#include <iostream>
#include <climits>
using namespace std; 
int findMaxColumn(int arr[][1000], int row, int col) {
    int max_sum = 0, currentCol = 0;
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += arr[i][j]; //Tinh tong tung hang
        }
        if (sum > max_sum) {
            max_sum = sum; 
            currentCol = j; 
        }
    }
    return currentCol;
}
int diagonalProduct(int arr[][1000], int row, int col) {
    int total = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col;j++) {
            if (i==j) {
                total *= arr[i][j];
            }
        }
    }
    return total; 
}
int main () {
    int arr[][1000] = {{-44,64,-6},{87,92,-19},{-92,53,-38},{-39,-92,21}};
    cout << findMaxColumn(arr, 4, 3);
    int arr1[][1000] = {{-45,18,-37},{-2,-31,24},{-48,-33,-48}};
cout << diagonalProduct(arr1,3,3);
}