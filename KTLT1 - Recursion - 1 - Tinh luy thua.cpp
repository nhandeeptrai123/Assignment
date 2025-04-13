#include<iostream>
#include<string>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

/* END of library */


int gcdRecursion(int p, int q)
{
    if (p == q) {
        return p;
    }
    else if (p > q) {
        return gcdRecursion(p - q, q);
    }
    else {
        return gcdRecursion(p, q - p);
    }
} 

int gcdIteration(int p, int q)
{
  while (p != q) {
    if (p > q) {
        p -= q;
    }
    else {
        q -= p;
    }
  }
    return p;
}

int main()
{
    int p,q;
    cin>>p>>q;
    cout<</*gcdRecursion(p,q)*/ " "<<gcdIteration(p,q);
    return 0;
}