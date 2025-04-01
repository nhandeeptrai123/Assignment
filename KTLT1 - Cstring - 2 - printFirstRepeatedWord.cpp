#include <iostream>
#include <cstring>
using namespace std; 
void printFirstRepeatedWord(char str[]) {
    char* word[100]; //Mang luu toi da 100 tu, moi tu toi da 31 ky tu 
    char* token = strtok(str," ");
    int word_count = 0; 
    bool found = false;
    while (token != NULL) {
        /*
        token = car 
        word[0] = car -> word_count = 1
        token = bike != word[0]
        */
       for (int i = 0; i < word_count; i++) {
           if (strcmp(word[i], token) == 0) {
               cout << token; 
               found = true;
               return; 
            }
        }
       if (word_count < 100) {
        word[word_count] = token;
        word_count++;
       }  
        /*word[0] = token = car; 
        word[1] = token
    
        */
        token = strtok(NULL, " ");
    }
    //Tach tiep tu NULL den dau cach tiep theo
    if (!found) {
        cout << "No Repetition";
    }
}    
int main () {
    char str[] = "   hello world " ;
    printFirstRepeatedWord(str);
}