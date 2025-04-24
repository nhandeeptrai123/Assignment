#include <iostream>
using namespace std; 
class ClockType
{
public:
    ClockType(int, int, int);
    ClockType();    
    void printTime() const;
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    

private:
    int hr;
    int min;
    int sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

void ClockType :: setTime(int hour, int minute, int second) {//Hàm này dùng để khởi tạo biến
    this -> hr = hour; 
    this -> min = minute;
    this -> sec = second;
}
void ClockType ::getTime(int& hour, int& minute, int& second) const {//dùng để gán giá trị cho từng biến bên ngoài class
    hour = (hr < 24 && hr >= 0) ? hr : 0;
    minute = (min < 60 && min >= 0) ? min : 0;
    second = (second < 60 && second >= 0) ? sec : 0;
}
//Clocktype có tham số
ClockType :: ClockType(int hour, int minute, int second) {
    setTime(hour, minute, second);
}
//Clocktype mặc định 
ClockType :: ClockType() {
    hr = 0; 
    min = 0;
    sec = 0;
}
int main () {
    ClockType myClock; //Đây chỉ là 1 biến 
    myClock.setTime(5, 4, 30); //Dùng để khởi tạo giá trị cho myclock 
    int hours,minutes,seconds;
    myClock.getTime(hours, minutes, seconds);
    cout << "Hours = " << hours << ", minutes = " << minutes << ", seconds = " << seconds << endl;
}