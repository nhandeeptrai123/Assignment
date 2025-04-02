#include <iostream>
#include <string>
using namespace std;
void deleteWord(string s, string s1){
    int pos = -1; 
    while (s.find(s1) != string::npos) {
            pos = s.find(s1);
            if (pos != -1) {
            s.erase(pos, s1.length()); //Thay the bang khoang trang
            }
            else {
                break;
            }
        }
    pos = -1;
    if (pos == -1) {
        cout << s; 
        return;
        //Neu khong tim thay tu nao nua thi in ra chuoi cuoi cung
    }
}
int main () {
    string s; 
    string s1;
    getline (cin,s);
    getline (cin,s1);
    deleteWord(s, s1);
}