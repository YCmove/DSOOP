#include <iostream>

using namespace std;

long long recursion(long long b, long long p, long long m)
{
    // p 是指數，把他做削減
    if (p == 0){
        return 1 % m;
    } else if (p == 1){
        return b % m;
    }

    if (p % 2 == 0){
        // power is even number
        long long temp = recursion(b, p/2, m);
        return (temp * temp) % m;
    } else {
        // power is odd number
        long long temp = recursion(b, p - 1, m);
        return ((b%m) * temp) % m;
    }



}



int main()
{
    long long B, P, M, temp;

    // 注意每次用while(cin.eof())都不會過！
    // while(!cin.eof()){
    while(cin >> B >> P >> M){
        
 
        long long result = recursion(B, P, M);
        // cout << "result: " << result << endl;

        cout << result << endl;
        // cout << "=======" << endl;
    }

    return 0;
}