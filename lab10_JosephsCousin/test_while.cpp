#include <iostream>

using namespace std;

int main(){

    int i = 1;

    while(i--){
        // 10個loop
        // 9 8 7 6 5 4 3 2 1 0 
        cout << i << " ";
    }
    cout << endl;

    i = 1;

    while(--i){
        // 9個loop
        // 9 8 7 6 5 4 3 2 1
        cout << i << " ";
    }
    cout << endl;

    return 0;
}