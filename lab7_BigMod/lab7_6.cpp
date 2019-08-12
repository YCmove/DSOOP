#include <iostream>

using namespace std;

long long recursion(long long b, long long p, long long m){
    if (p == 0){
        return 1 % m;
    }else if (p == 1){
        return b % m;
    }

    if (p % 2 == 0){
        long long temp = recursion(b, p/2, m);
        return (temp * temp) % m;
    } else {
        long long temp = recursion(b, p - 1,m);
        return ((b%m)*temp)%m;
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