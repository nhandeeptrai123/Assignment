/*
Viết hàm void calMoney(string price, string buy) đọc vào 2 file price.txt và buy.txt.


Trong đó:

File price.txt chứa thông tin về các sản phẩm, gồm: Dòng đầu tiên chứa số nguyên dương N (N <= 20) là số lượng sản phẩm hiện có trong cửa hàng. N dòng tiếp theo mỗi dòng chứa 2 số nguyên dương là ID và giá của các sản phẩm tương ứng

     Ví dụ:

          3

          1 10

          2 15

          3 12

Có nghĩa là: hiện tại có 3 sản phẩm được bán trong cửa hàng, sản phẩm 1 giá 10 sản phẩm 2 giá 15 và sản phẩm 3 có giá là 12.

File buy.txt chứa thông tin về việc mua hàng hóa của khách hàng. Dòng đầu tiên chứa số nguyên dương M là số lượng khách hàng mua hàng trong 1 ngày. M dòng tiếp theo mỗi dòng chứa thông tin như sau: sẽ có  giá nhiều trị nằm trên một hàng, cách nhau bởi một khoảng trắng. Giá trị đầu tiên sẽ là tên khách hàng (dạng string), các giá trị còn lại sẽ đi theo cặp với nhau, tương ứng là: <ID sản phẩm>_<số lượng tương ứng>

     Ví dụ:

          2

          A 1 2 2 3

          B 1 3 3 2

Có nghĩa là có 2 khách hàng A và B, A mua 2 sản phẩm loại 1 và 3 sản phẩm loại 2; B mua 3 sản phẩm loại 1 và 2 sản phẩm loại 3.

Lưu ý: ID của sản phẩm và tên khách hàng là duy nhất (không lặp lại).

Tính số tiền mỗi khách hàng cần trả, sau đó xuất kết quả ra màn hình.

Đầu vào:

2 biến price (là tên của file chứa thông tin sản phẩm) và buy (là tên của file chứa thông tin mua hàng).

Đầu ra:

Số tiền mỗi khách hàng cần trả
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const int MAX = 1000;
void calMoney(string price, string buy) {
     //price is the function used to read the product price, buy is information of customer 
     ifstream priceFile(price);//Read the product file 
     if (!priceFile.is_open()) {
          cout << "Cannot open price file \n";//Check if priceFile cant open
          return;
     }
     int productID[MAX], productPrice[MAX]; //are used to store the product information
     int linePrice; 
     priceFile >> linePrice;//Get the amount of product
     for (int i = 0; i < linePrice; i++) {
          priceFile >> productID[i] >> productPrice[i];
     }
     for (int i = 0; i < linePrice; i++) {
          cout << productID[i] << ' ' << productPrice[i];
          cout << endl;
     }
     priceFile.close();

     //Xu ly ham buy
     ifstream buyFile(buy);
     if (!buyFile.is_open()) {
          cout << "can not open file \n";
          return; 
     }
     int numBuy;
          string name, line, nameID[MAX]; //Id customers
          buyFile >> numBuy; //number of customers
          buyFile.ignore(); //Bo qua ki tu xuong dong
          for (int k = 0; k < numBuy; k++) { 
          getline (buyFile, line); //Nhap vo 1 hang de xu ly
          istringstream iss(line); //Tach chuoi ra de xu ly 
          string name; 
          int id, amount, total = 0; //mã sản phẩm - số lượng - tổng tiền phải trả 
               iss >> name;
          while (iss >> id >> amount) { //Tách chuỗi ra thành các token nhỏ để xử lý
               for (int j = 0; j < linePrice; j++) {
                    if (id == productID[j]) {//Dò với danh sách sản phẩm ở trên
                         total += productPrice[j] * amount; //Tính số tiền 
                    }
               }
          }
          cout << name << ' ' << total << endl; 
     }
}
using namespace std; 
int main () {
    calMoney("price.txt", "buy.txt");
}