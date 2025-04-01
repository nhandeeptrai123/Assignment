#include <iostream>
using namespace std; 
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