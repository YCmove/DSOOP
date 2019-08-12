#include <iostream>

using namespace std;

// 這樣就是直接算的了... overflow...
long long recursion(long long b, long long p, long long m){
    // cout << "start recursion b: " << b << " / p: " << p << " / m: " << m << endl;
    // 拆解指數
    if (p == 0){
        // cout << "(p == 0) b: " << b << " / p: " << p << " / m: " << m << endl;
        return 1 % m;
    } else if (p == 1){
        // b的一次方的餘數
        // cout << "(p == 1) b: " << b << " / p: " << p << " / m: " << m << endl;
        // cout << "(p == 1) return value: " << b % m << endl;
        return b % m;
    } 
    // 用 2 做 divide and conquer
    if (p % 2 == 0){
        // 被 2 整除, 偶數
        long long temp = recursion ( b, p / 2, m );
        long long x = temp % m;
        long long y = temp % m;
        return (x * y) % m;
    } else {
        // 沒有 被 2 整除，奇數
        long long temp = b % m;
        long long recur = recursion(b, p - 1, m);
        return (temp * recur) % m;
    }
}

int main(){

    long long b, p, m;
    while (cin >> b >> p >> m){
        long long result = recursion(b, p, m);
        cout << result << endl;
    }

    return 0;
}