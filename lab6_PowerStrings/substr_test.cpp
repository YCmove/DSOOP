#include <iostream>
#include <string>

using namespace std;

int main(){
    string s = "abcdefg";
    // 第二個參數代表，從第一個參數的index數來（包括自己） 共取幾個！
    cout << s.substr(0, 0) << endl; // 沒有東西！
    cout << s.substr(0, 1) << endl; // a
    cout << s.substr(0, 4) << endl; // abcd
    cout << s.substr(2, 4) << endl; // cdef

    return 0;
}