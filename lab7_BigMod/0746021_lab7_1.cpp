#include <iostream>
// #include <algorithm>

using namespace std;

long long recursion(long long B, long long P, long long M)
{
    // 遞迴把P指數削減
    if ( P == 0 ){ 
        // 指數為零（P指數降低到了零）
        return 1 % M;
    } else if (P == 1){
        return B % M;
    }
 
    // Divide and Conquer !!!

    // if ( P % 2 != 0) { // 沒有被2整除
    //     long long temp = B % M;
    //     long long recur = recursion(B, P - 1, M);
    //     return (temp * recur) % M;

    // } else { // 被2整除
    //     long long temp = recursion ( B, P / 2, M );
    //     long long x = temp % M;
    //     long long y = temp % M;
    //     return (x * y) % M;
    // }
    if ( P % 2 == 0) {
        long long temp = recursion ( B, P / 2, M );
        long long x = temp % M;
        long long y = temp % M;
        return (x * y) % M;
    } else {
        long long temp = B % M;
        long long recur = recursion(B, P - 1, M);
        return (temp * recur) % M;
    }
}



int main()
{
    long long B, P, M, temp;

    // 注意每次用while(cin.eof())都不會過！
    // while(!cin.eof()){
    while(cin >> B >> P >> M){
        // cout << "B: " << B << endl;
        // cout << "P: " << P << endl;
        // cout << "M: " << M << endl;
        
        // 一個一個減不可行！！
        // long long temp = 1;
        // while (P != 0) {
        //     P = P - 1;
        //     if (B < M){
        //         cout << "[B < M]" << endl;
        //         cout << "P: " << P << endl;
        //         B = B * B;
        //     } else {
        //         cout << "[B > M]" << endl;
        //         cout << "P: " << P << endl;
        //         temp = B % M * temp;
        //     }
        // }

        long long result = recursion(B, P, M);
        // cout << "result: " << result << endl;

        cout << result << endl;
        // cout << "=======" << endl;
    }

    return 0;
}