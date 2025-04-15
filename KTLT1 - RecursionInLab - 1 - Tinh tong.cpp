#include <iostream>
using namespace std; 
int recursiveSum(int arr[], int size) {
   if (size == 0) {
    return 0;
   }
   return arr[size - 1] + recursiveSum(arr, size - 1);
}
int main () {
    int arr[] = {1,2,3,4,5};
    int size = 5;
    cout << recursiveSum(arr, size);
}