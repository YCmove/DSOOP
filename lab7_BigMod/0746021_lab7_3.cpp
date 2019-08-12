#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

long long recursion(long long A, long long P, long long M)
{
    if ( P == 0 ){ 
        // 指數為零
        return 1 % M;
    } else if (P == 1){
        return A % M;

    } else if (P == 2){
        return A % M;
    }

    // Divide and Conquer !!!

    if ( P % 3 == 1 ) { // 沒有被3整除
        long long temp = A % M;
        long long recur = recursion(A, P - 1, M);
        return (temp * recur) % M;

    } else if (P % 3 == 2){
        long long recur = recursion(A, P - 2, M);
        long long temp1 = A % M;
        long long temp2 = A % M;
        return (temp1 * temp2 * recur) % M;
        
    } else { // 被3整除
        long long temp = recursion ( A, P / 3, M );
        long long x = temp % M;
        long long y = temp % M;
        long long z = temp % M;

        return (x * y * z) % M;
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