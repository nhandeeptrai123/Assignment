#include <iostream>
#include <string>
#include <fstream>
using namespace std; 
void uppercase(string output) {
    string str; 
    getline(cin, str);
    for (char &c : str) {
        if (islower(c)) {
            c = toupper(c);
        }
    }
    ofstream outFile(output);//Mo file de viet them vao cuoi
    if (outFile.is_open()) {
        outFile << str;
        outFile.close();
    }
}