#include <iostream>
#include <cstring> 
using namespace std; 
int findLength(char str[]) {
    int index = 0;
    int count = 0;
    while (str[index] != '\0') {
        count++;
        index++;
    }
    return count;
}
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
void process(const char str[], char outstr[]) {
    int i = 0, j = 0; 
    while (str[i] != '\0') {
        if (str[i] == ' ') {
                if (str[i+1] == ' ') {
                if (str[i+2] == '\0') {
                    break;
                }
                else if (isalpha(str[i+2])) {
                //Loai bo 2 khoang trang dau chuoi
                i++;
                }
                else {
                    i++;
                }
            }
            else {
                if (i>1) {
                outstr[j] = str[i]; //Neu chi co 1 khoang trang thi se dua vao outstr va tang i len
                j++;
                }
                i++;
            }
        }
        else {
            outstr[j] = str[i]; //Con neu la chu thi se dua luon vao mang
            i++; j++;
        }
    }
    outstr[j] = '\0';
    deleteGap(outstr);
    return; 
}
int main () {
    const int MAX_SIZE = 100;
char str[] = "   abc   def   " ;
char outstr[MAX_SIZE];
process(str, outstr);
cout << outstr;
}