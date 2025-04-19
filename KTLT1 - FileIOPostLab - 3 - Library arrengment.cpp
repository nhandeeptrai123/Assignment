#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std; 
const int MAX = 100;

void manage(string library, string book, string author) {
        ifstream libFile(library); //Đọc file chứa thông tin các thư viện 
        if (!libFile.is_open()) {
            cout << "cant open file"; 
            return;
        }
        int nLib; 
        libFile >> nLib; //Nhập vào số lượng thư viện được khảo sát 
        string nameLib[MAX], line; 
        int ID[MAX][5];//có n dòng, mỗi dòng chứa 5 sách
        libFile.ignore(); //Xóa kí tự xuống dòng của hàng đầu tiên
        for (int k = 0; k < nLib; k++) {
            getline (libFile, line);
            istringstream iss (line); //Tách các từ ra để xử lý 
            iss >> nameLib[k]; //Nhập vào tên của các thư viện 
            int i = 0;
            int temp;
            while (iss >> temp) {
                ID[k][i] = temp; 
                temp = 0;
                i++;
            }
        }
        libFile.close(); //Đóng file sau khi xử lý xong 
        //////////////////////////////////////////
        ifstream bookFile(book); //Mở file book để xử lý 
        if (!bookFile.is_open()) {
            cout << "can not open file";
            return;
        }
        int bookNum; 
        bookFile >> bookNum; //Nhập vào số lượng sách 
        bookFile.ignore(); 
        int yearBook[5],idBook[5];//dùng đê chứa năm xuất bản
        string typeBook[5]; //Thể loại của từng quyển
        for (int k = 0; k < bookNum; k++) {
            getline (bookFile, line);
            istringstream iss(line);
            int idCheck = 0, yearCheck = 0;
            string typeCheck;
            while (iss >> idCheck >> yearCheck >> typeCheck) {
                idBook[k] = idCheck;
                yearBook[k] = yearCheck; 
                typeBook[k] = typeCheck;
            }
        }
        bookFile.close();        
        ///////////////////////////////////
        ifstream authorFile(author); 
        if (!authorFile.is_open()) {
            cout << "can not open file";
            return; 
        }
        int nAuthor; 
        authorFile >> nAuthor; //Nhập vào số lượng tác giả 
        authorFile.ignore();
        int Author[MAX][MAX];
        string nameAuthor[nAuthor]; 
        for (int i = 0; i < nAuthor; i++) {
            getline(authorFile, line); 
            stringstream ss(line); 
            ss >> nameAuthor[i];
            int idCheck, countID = 0; 
            string nameCheck;
            while (ss >> idCheck) {
                Author[i][countID] = (idCheck);
                idCheck = 0;
                countID++;
            }
        }
        authorFile.close();
        //Kiểm tra trong thư viện L có tác phẩm của tác giả A không
        string L, A; //L là tên thư viện, A là tên tác giả
        cin >> L >> A;
        int indexLib = -1, indexAuthor = -1;
        //Tìm chỉ số của thư viện
        for (int i = 0; i < nLib; i++) {
            if (nameLib[i] == L) {
                indexLib = i; 
                break;
            }
        }
        //Tìm chỉ số của tác giả
        for (int i = 0; i < nAuthor; i++) {
            if (nameAuthor[i] == A) {
                indexAuthor = i;
                break;
            }
        }
        if (indexAuthor == -1 || indexLib == -1) {
            return;
        }//Nếu không tìm ra thì kết thúc chương trình
        bool found = false; //Đánh dấu khi tìm ra được 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < MAX; j++) {
                if (ID[indexLib][i] == 0) break;//nếu xuất hiện id sách cần tìm thì dừng tìm
                if (Author[indexAuthor][j] == 0) break; //Nếu xuất hiện tác giả cần tìm thì dừng tìm
                if (ID[indexLib][i] == Author[indexAuthor][j]) {
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if (found) cout << "TRUE";
        else cout << "FALSE";
        
}
int main () {
manage("library.txt","book.txt","author.txt");
}