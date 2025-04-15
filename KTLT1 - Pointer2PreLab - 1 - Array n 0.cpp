#include <iostream>
using namespace std; 
int* zeros(int n) {
   if (n <= 0) return nullptr;
   int* arr = new(std::nothrow) int[n];
   if (arr == nullptr) 
    return nullptr; 
   for (int i = 0; i < n; i++) {
    arr[i] = 0;
   }
   return arr;
}
int main () {

}