#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 
typedef long long ll;
//Nhap vao 2 diem A, B va tinh khoang cach voi do chinh xac 4 chu so 
struct pos {
double x, y;
};

double dis(pos a, pos b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (b.y - a.y) * (b.y - a.y));
}
int main () {
int n; cin >> n; 
while (n--) {
    pos A, B; 
    cin >> A.x >> A.y >> B.x >> B.y; 
    cout << fixed << setprecision(4) << dis(A,B);  
}
}