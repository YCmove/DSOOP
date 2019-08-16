#include <iostream>

using namespace std;

int main(){

    int num = 12345;

    int reminder = 0;
    int reversed = 0;

    while(num != 0){
    // while(num != 10){
        reminder = num % 10;
        reversed = reversed * 10 + reminder;
        num /= 10;
    }

    cout << reversed << endl;


    return 0;
}