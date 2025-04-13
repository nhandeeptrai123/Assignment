#include <iostream>
using namespace std; 
bool checkElementsUniqueness(int* arr, int n) {
    if (n <= 1) 
        return true;
    for (int i = 0; i < n - 1; i++) {
        int check = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == check) {
                return 0;
            }
        }
    }
    return true;
}
int main () {
    int n;
cin >> n;
int* arr = new int[n];
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
cout << checkElementsUniqueness(arr, n);
delete[] arr;
}