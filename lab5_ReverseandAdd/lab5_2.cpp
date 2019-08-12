#include <iostream>

using namespace std;

unsigned long reverse(unsigned long num){
    unsigned long reminder = 0;
    unsigned long reversed = 0;
    // 重要！
    while(num != 0){
        reminder = num % 10;
        reversed = reversed * 10 + reminder;
        num /= 10;
    }
    return reversed;
}

bool check_pali(unsigned long num){
    unsigned long reversed = reverse(num);
    if (num == reversed){
        return true;
    }
    return false;
}


int main(){
    int n_number;
    cin >> n_number;

    for (int i = 0; i < n_number; i++){
        unsigned long num;
        int counter = 1;
        cin >> num;
        // cout << reverse(num) << endl;
        
        // 一定要翻轉相加至少一次！
        unsigned long result = num + reverse(num);
        while(!check_pali(result)){
            result += reverse(result);
            counter ++;
        }

        cout << counter << " " << result << endl;
    }



    return 0;
}