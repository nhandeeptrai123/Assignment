#include <iostream>
#include <string>
using namespace std;
class Time {
    private: 
    int hour;
    int minute; 
    int second; 
    public:
    Time(int hour, int minute, int second) {
        this -> hour = hour; 
        this -> minute = minute; 
        this -> second = second;
    }
    void setTime(int hour, int minute, int second) {
        this -> hour = hour; 
        this -> minute = minute; 
        this -> second = second;
    }
    void setHour(int hour) {
        this -> hour = hour; 
    }
    void setMinute(int minute) {
        this -> minute = minute; 
    }
    void setSecond(int second) {
        this -> second = second;
    }
    int getHour () {
        return hour;
    }
    int getMinute() {
        return minute;
    }
    int getSecond() {
        return second;
    }
    void nextSecond() {
        if (hour == 23 && minute == 59 && second == 59) {
            hour = 0;
            minute = 0;
            second = 0;
            return;
        }
        else if (minute == 59 && second == 59) {
            hour++;
            minute = 0;
            second = 0;
            return;
        }
        else if (second == 59) {
            minute++;
            second = 0;
            return;
        }
        second++;
    }
    void previousSecond() {
        if (hour == 0 && minute == 0 && second == 0) {
            hour = 23; 
            minute = 59;
            second = 59;
            return;
        }
        else if (minute == 0 && second == 0) {
            hour--;
            minute = 59;
            second = 59;
            return;
        }
        else if (second == 0) {
            second = 59;
            minute--;
            return;
        }
        second--;
    }
    void display() {
        string hour = to_string(this -> hour);
        string minute = to_string(this -> minute);
        string second = to_string(this -> second);
        if (hour.length() == 1) 
            hour = "0" + hour;
        if (minute.length() == 1) 
            minute = "0" + minute;
        if (second.length() == 1) 
            second = "0" + second;
        cout << hour << ":" << minute << ":" << second << endl; 
    }
};
int main () {
    int n; cin >> n;
    while (n--) {
    int hour, minute, second;
    cin >> hour >> minute >> second; 
    Time t(hour, minute, second);
    t.display();
   //t.nextSecond();
    t.display();
    //t.previousSecond();
    t.previousSecond();
    t.display();
	return 0;
    }
}