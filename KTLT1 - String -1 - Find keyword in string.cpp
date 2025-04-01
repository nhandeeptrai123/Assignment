#include <iostream>
#include <string>
using namespace std;
//Hiện thực hàm findAllIndex(string s1, string s2) để in ra tất cả các vị trí xuất hiện 
//của kí tự đầu tiên của chuỗi s2 trong chuỗi s1. Nếu không tìm thấy in ra -1. Các vị trí tìm thấy 
//sẽ cách nhau một khoảng trắng, sau vị trí cuối cùng, 
//không in thêm bất kỳ ký tự nào (kể cả khoảng trắng, dấu xuống hàng)

void findAllIndex(string s1, string s2){
    char firsts2 = s2[0];
    char s1Char[s1.size()];
    for (int i = 0; i < s1.size();i++) {
        s1Char[i] = s1[i]; //dung de chuyen xau thanh ky tu
    }
    int count = 0, index = 0;
    int position[100];//mang dung de luu vi tri
    while (s1Char[index] != '\0') {
        if (s1Char[index] == firsts2) {
            position[count] = index; 
            count++;
        }
        index++; 
    }
    if (count != 0) {
        for (int i = 0; i < count; i++) {
            if (i == count - 1) {
                cout << position[i];
            }
            else {
                cout << position[i] << ' ';
            }
        }
    }
    else {
        cout << "-1";
    }
}

int main () {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2); 
    findAllIndex(s1,s2);
    
}