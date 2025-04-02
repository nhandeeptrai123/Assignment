#include <iostream>
using namespace std; 

void encrypt (char *str, int shift) {
    if (str == nullptr)
        return;
        //Kiem tra xem co hop le hay khong
        int real_shift = shift % 26; //Chuan hoa shift
        if (real_shift < 0) {
            real_shift += 26; //Neu be hon 0 thi cong them 26 
        }
        if (real_shift == 0) {
            return; 
        }
            for (int i = 0; str[i] != '\0'; ++i) {
                char currentChar = str[i];
                if (currentChar >= 'a' && currentChar <= 'z') {
                    // Xử lý chữ cái thường
                    char shiftedChar = 'a' + (currentChar - 'a' + real_shift) % 26;
                    str[i] = shiftedChar;
                } else if (currentChar >= 'A' && currentChar <= 'Z') {
                    // Xử lý chữ cái hoa
                    char shiftedChar = 'A' + (currentChar - 'A' + real_shift) % 26;
                    str[i] = shiftedChar;
                }
        }
}
      
void decrypt (char *str, int shift) {
    if (str == nullptr)
    return;
    //Kiem tra xem co hop le hay khong
    int real_shift = shift % 26; //Chuan hoa shift
    if (real_shift < 0) {
        real_shift += 26; //Neu be hon 0 thi cong them 26 
    }
    if (real_shift == 0) {
        return; 
    }
        for (int i = 0; str[i] != '\0'; ++i) {
            char currentChar = str[i];
            if (currentChar >= 'a' && currentChar <= 'z') {
                // Xử lý chữ cái thường
                char shiftedChar = 'a' + (currentChar - 'a' - real_shift + 26) % 26;
                str[i] = shiftedChar;
            } else if (currentChar >= 'A' && currentChar <= 'Z') {
                // Xử lý chữ cái hoa
                char shiftedChar = 'A' + (currentChar - 'A' - real_shift + 26) % 26;
                str[i] = shiftedChar;
            }
    }
}
int main () {
    int n, shift; 
    cin >> n >> shift;
    char* text = new char[n+1];
    for(int i = 0; i < n; i++) cin >> text[i];
    text[n] = 0;
    
    encrypt(text, shift);
    cout << text << '\n';
    decrypt(text, shift);
    cout << text;
    
    delete[] text;
}