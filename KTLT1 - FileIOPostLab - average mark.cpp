#include <iostream>
#include <fstream>
#include <map>
using namespace std; 
void studendGrading(string fileName) {
    ifstream fileRead(fileName);
    if (!fileRead.is_open()) {
        return; //Kiem tra xem file mo thanh cong hay khong 
    }
   int N; fileRead >> N; //Nhap vao so hang 
   int countA = 0, countB = 0, countC = 0, countD = 0; 
   for (int i = 0; i < N; i++) {
       double nmdt, ktlt, dsa, ppl; 
       fileRead >> nmdt >> ktlt >> dsa >> ppl; 
       double GPA = (nmdt + ktlt + dsa + ppl) / 4.0; //tinh diem trung binh cua 4 mon
       if (GPA >= 8) countA++;
       else if (GPA >= 6.5 && GPA < 8) countB++;
       else if (GPA > 5.0 && GPA <6.5) countC++;
       else countD++;
   }
   
        cout << "A " << countA << endl;   
        cout << "B " << countB << endl;
        cout << "C " << countC << endl;
        cout << "D " << countD << endl;
}

int main () {
studendGrading("grade.txt");
}