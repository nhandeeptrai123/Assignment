#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
bool palindrome(string strg) {
    int left = 0, right = strg.length() - 1; 
    while (left <= right) {
        if (strg[left] != strg[right]) {
            return false;
        }
        left++, right--;
    }
    return true;
}
bool palindromeRecursion(string s, int left, int right) {
    if (left >= right) {
        return true; //diem dung de quy 
    }
    return (s[left] == s[right] && palindromeRecursion(s, left + 1 , right -1));
}
bool palindromeRecursion(string s) {   
    return (palindromeRecursion(s, 0, s.length()-1));
}
int main () {
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
    ifstream file("palindrome.txt");
    if (!file.is_open()) 
    return 0;
    // BEGIN YOUR IMPLEMENTATION [2]
    string str;
    while(getline(file,str)) {
        if (!str.empty()&& str[0] == '*') 
        return 0;
       // while (str != "*") {
        if (palindrome(str)) {
            cout << "true ";
        }
        else cout << "false ";
        if (palindromeRecursion(str)) 
        cout << "true";
        else cout << "false ";
        cout << endl;
        //}
    }
    // END YOUR IMPLEMENTATION [2]
    file.close();
    return 0;
}