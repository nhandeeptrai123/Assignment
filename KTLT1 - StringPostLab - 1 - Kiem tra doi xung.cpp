#include <iostream>
#include <string>

using namespace std;

// Hàm mở rộng từ vị trí trung tâm để tìm palindrome
void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        int currLen = right - left + 1;
        if (currLen > maxLen) {
            start = left;
            maxLen = currLen;
        }
        left--;
        right++;
    }
}

int main() {
    string s;
    getline(cin, s); // Đọc cả dòng (bao gồm khoảng trắng)

    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < s.length(); i++) {
        // Trường hợp độ dài lẻ
        expandAroundCenter(s, i, i, start, maxLen);
        // Trường hợp độ dài chẵn
        expandAroundCenter(s, i, i + 1, start, maxLen);
    }

    cout << s.substr(start, maxLen) << endl;

    return 0;
}