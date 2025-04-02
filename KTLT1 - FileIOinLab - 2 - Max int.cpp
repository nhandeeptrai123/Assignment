#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
double findMax(double a, double b) {
    double max = a; 
    if (max < b) {
        max = b; 
    }
    return max;
}
void process(string fileName) {
    ifstream fileRead(fileName);//Mo file de doc 
    if (!fileRead.is_open()) {
        return;
    }
        int N, M; //Dung de luu hang va cot
        fileRead >> N >> M;
        if (N <= 0 || M <=0) {
            return;
        }
        double maxEachRow[N]; //dung de luu gia tri lon nhat cua tung hang 
        double maxAll = -9999999999;
        for (int i = 0; i < N; i++) {
            maxEachRow[i] = -999999999999;
            for (int j = 0; j < M; j++) {
                double num;
                fileRead >> num; 
                maxEachRow[i] = findMax(maxEachRow[i], num); //Tim so' lon' nhat' tung` dong`
                maxAll = findMax(maxAll, num);
            }
        }
        fileRead.close();
        for (auto c : maxEachRow) {
            cout << c << " ";
        }
        cout << maxAll;
    }

int main () {
process("example.txt");
}