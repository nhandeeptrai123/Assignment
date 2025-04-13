#include <iostream>
#include <cstring>
using namespace std; 
void deleteGap(char str[]) {
    int start = 0, end = strlen(str) - 1;
    while (str[start] == ' ' && str[start] != '\0') {
        start++;
    }
    while (str[end] == ' ' && end > start) {
        end--;
    }
    int newLength = end - start + 1; 
    for (int i = 0; i < newLength; i++) {
        str[i] = str[i+start];
    }
    str[newLength] = '\0';
}

void deleteSpace(const char str[], char outstr[]) {
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') { //Neu ky tu hien tai la khoang trang
            if(str[i+1] == ' ') { //Kiem tra tiep ky tu tiep theo co la khoang trang hay khong
                if (str[i+2] == '\0') { //Kiem tra tiep ky tu tiep theo nua co la diem cuoi cung hay khong
                    break; //Ket thuc vong lap
                }
                else if (isalpha(str[i+2])) { //Neu ky tu thu i+2 la ky tu thi tang i len
                    i++; 
                }
                else {
                    i++;
                }
            }
            else {
                if (i > 1) {
                    outstr[j] = str[i]; //Neu chi co 1 khoang trang thi dua vao luon
                    j++;
                }
                i++;
            }
        }
        else {
            outstr[j++] = str[i++];
        }
    }
    outstr[j] = '\0';
    deleteGap(outstr);
    return; 
}

void possibleWord(const char str[], char outstr[]) { //Kiem tra xem co phai la ky tu hop le khong
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            outstr[j++] = str[i++];
        }
        if (isalpha(str[i])) {
            outstr[j++] = str[i++];
        }
        else {
            ++i;
        }
    }
    outstr[j] = '\0';
    return; 
}

void standardWord(const char str[], char outstr[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (isupper(str[i])) {
            outstr[j++] = tolower(str[i++]);
        }
        else {
            outstr[j++] = str[i++];
        }
    }
    outstr[i] = '\0';
    return; 
}
void finalWord(const char str[], char outstr[]) {
    int i = 0, j = 0; 
    while (str[i] != '\0') {
        outstr[0] = toupper(str[0]); //Viet hoa chu cai dau tien 
        if (str[i] == ' ') {
            outstr[j++] = str[i++]; //Tu hien tai se chua khoana trang;
            outstr[j++] = toupper(str[i++]); //Tu dung dang sau khoang trang se duoc viet hoa
        }
        else {
            outstr[j++] = str[i++];
        }
    }
    outstr[j] = '\0';
    return; 
}
void process(const char str[], char outstr[]) {
    deleteSpace(str, outstr);
    possibleWord(outstr, outstr);
    standardWord(outstr, outstr);
    finalWord(outstr, outstr);
}

int main () {
    const int MAX_SIZE = 100;
    char outstr[MAX_SIZE];
    char str[] = "Vo n129Gu!yen Q83\\uynH hu@48ong";
    process(str, outstr);
    cout << outstr;
}