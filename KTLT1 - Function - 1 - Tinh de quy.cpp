#include <iostream>

using namespace std;
// implement calculate factorial function in here
int gt(int n) {
    if (n == 1) return 1; 
    return gt(n-1) * n; 
}

int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    // call function calculateFactorial in here and assign value to the variable result
    result = gt(N);

    cout << result << endl;
    return 0;
}