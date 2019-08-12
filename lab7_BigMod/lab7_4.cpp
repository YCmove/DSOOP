#include <iostream>

using namespace std;

// 這樣就是直接算的了... overflow...
long long recursion(long long b, long long p, long long m){
    cout << "start recursion b: " << b << " / p: " << p << " / m: " << m << endl;
    // 拆解指數
    if (p == 0){
        cout << "(p == 0) b: " << b << " / p: " << p << " / m: " << m << endl;
        return 1 % m;
    } else if (p == 1){
        // b的一次方的餘數
        cout << "(p == 1) b: " << b << " / p: " << p << " / m: " << m << endl;
        cout << "(p == 1) return value: " << b % m << endl;
        return b % m;
    } 
    // else if (p == 2){
    //     // b的一次方的餘數
    //     cout << "(p == 2) b: " << b << " / p: " << p << " / m: " << m << endl;
    //     cout << "(p == 2) return value: " << ((b % m)*(b % m))%m << endl;
    //     return ((b % m)*(b % m))%m;
    // }

    // long long result;

    // 用 2 做 divide and conquer
    if (p % m == 0){
        // 被 2 整除, 偶數
        // cout << "2. b: " << b << " / p: " << p << " / m: " << m << endl;
        // long long temp = recursion(b, p / 2, m);
        // // cout << "2. temp: " << temp << endl;
        // result = (temp * temp) % m;
        // return result;
        long long temp = recursion ( b, p / 2, m );
        long long x = temp % m;
        long long y = temp % m;
        return (x * y) % m;
    } else {
        // 沒有 被 2 整除，奇數
        long long temp = b % m;
        long long recur = recursion(b, p - 1, m);
        return (temp * recur) % m;
        // cout << "1. b: " << b << " / p: " << p << " / m: " << m << endl;
        // long long temp = recursion(b, p - 1, m);
        // cout << "1. temp: " << temp << endl;
        // result = (temp * (b%m)) % m;
        // cout << "1. result: " << result << endl;
        // return result;
        

    }

    

}

int main(){

    long long b, p, m;
    while (cin >> b >> p >> m){
        cout << recursion(b, p, m) << endl;
        cout << "----------" << endl;
    }

    return 0;
}