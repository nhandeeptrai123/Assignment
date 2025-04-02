#include <iostream>
using namespace std; 
void replaceString(string s, string s1, string s2){
    int lnStr = s.size();
    int pos = -1, lastpos; //Dung de luu vi tri xuat hien cuoi cung cua s1 trong s
    pos = s.rfind(s1); //In ra vi tri xuat hien cuoi cung cua chuoi con
    if (pos == -1) {
        cout << s;
        return; 
    }
    s.replace(pos,s1.length(),s2);
    cout << s;
}
int main () {
string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
string s1 = "skibidi";
string s2 = "ong";
replaceString(s, s1, s2);
}