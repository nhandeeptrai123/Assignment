#include <iostream>
using namespace std; 
int** readArray() {
    int rows = 3, cols = 3; 
    //Khoi tao con tro mang 2 chieu
    int **array = new int*[rows]; //tạo ra 1 con trỏ trỏ đến kiểu int, đây là mảng 2 chiều
    //new int*[rows] -> tạo ra rows con trỏ, mỗi con trỏ trỏ đến 1 dòng trong mảng
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];//Moi dong la 1 con tro 
    }
    for (int i = 0; i < rows; i++) {
        int val; //Bien dung de nhap gia tri 
        bool ValCheck = false; //bien dung de kiem tra xem so 0 xuat hien o dau 
        for (int j = 0; j < cols;j++) {
            cin >> val; 
            if (val < 0 || val > 1000) {
                j--; 
                cin >> val; //Nhap lai gi tri neu khong hop le 
            }
            else {
                array[i][j] = val; 
            }
            if (array[i][j] == 0) {
                ValCheck = true; //Kiem tra neu la so 0 thi danh giau la tim thay 
            }
            if (ValCheck) {
              for (int k = j + 1; k < cols; k++) {
                array[i][k] = 0; 
              } 
              break;
            }
        }
    }
    return array; 
}
int main () {
int **matrix = readArray();
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3;j++) {
        cout << matrix[i][j] << ' ';
    }
    cout << endl;
}
for (int i = 0; i < 3; i++) {
    delete[] matrix[i];
}
delete[] matrix;
}



