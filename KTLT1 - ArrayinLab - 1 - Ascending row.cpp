#include <iostream>
#include <string>
using namespace std; 
int ascendingRows(int arr[][1000], int row, int col) {
bool possible = false; 
int rowF = 0;
for (int i = 0; i < row; i++) {
     for (int j = 0; j < col - 1; j++) {
        if (arr[i][j] < arr[i][j+1]) {
            possible = true;
        }
        else {
            possible = false;
            break;
        }
    }
    if (possible == true) {
        rowF++;
    }
}
return rowF;
}
int main () {
int arr[][1000] = {{32,4,9},{-80,37,71},{-91,-79,-55}};
cout << ascendingRows(arr,3, 3);
}