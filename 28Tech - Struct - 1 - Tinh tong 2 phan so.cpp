#include <iostream>
using namespace std; 
typedef long long ll; 
struct phanso {
    ll tu, mau;
};

void nhap(phanso &p) {
cin >> p.tu >> p.mau; 
//Nhập tử số và mẫu số 
}
ll gcd(int a, int b) {
    if (a == b) {
        return a;
    }
    else if (a > b) {
        return gcd(a - b, b);
    }
    else {
        return gcd(a, b - a);
    }
}
void rutGon(phanso &p) {
    ll mini = gcd (p.tu, p.mau);
    p.tu /= mini;
    p.mau /= mini;
}

phanso tong(phanso &p, phanso &q) {
    ll bcd = p.mau * q.mau; 
    p.tu *= q.mau;
    q.tu *= p.mau; 
    p.tu += q.tu; 
    p.mau = bcd;
    phanso sum; 
    sum.tu = p.tu; 
    sum.mau = p.mau; 
    rutGon(sum);
    return sum; 
}
void in(phanso &p) {   
    cout << p.tu << '/' << p.mau; 
}
int main () {
    phanso p, q; 
    nhap(p); nhap(q);
    phanso t = tong(p,q);
    in(t);
}