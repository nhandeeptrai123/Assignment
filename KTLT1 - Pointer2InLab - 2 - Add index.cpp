//Hiện thực hàm void addElement(int*& arr, int n, int val, int index) nhận vào một mảng động arr 
//có chính xác n phần tử và tiến hành chèn giá trị val vào vị trí thứ index.
#include <iostream>
using namespace std; 
void addElement(int*& arr, int n, int val, int index) {
  int *newArr = new int[n + 1]; //Tao mang moi
  for (int i = 0; i < index; i++) {
    newArr[i] = arr[i]; //Copy mang cu qua
  }
  newArr[index] = val; //Thay the vi tri index
  for (int i = index; i < n; i++) {
    newArr[i+1] = arr[i];//copy phan con lai cua mang
  }
  delete[] arr; 
  arr = newArr; //tro mang cu vao mang moi
  delete[] newArr;
}
int main () {
    int n; 
    cout << "n "; cin >> n;
    cout << endl;
    int *arr = new int[n];
    cout << "ghi: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr+i);
    }
    cout << "index, val: ";
    cout << endl;
    int index, val;
    cin >> index >> val;
    cout << "in: " << endl;
    n++;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    delete[] arr;
}