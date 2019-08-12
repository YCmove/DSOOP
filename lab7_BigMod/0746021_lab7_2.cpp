#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int  bigmod ( unsigned int a, unsigned int p, unsigned int m )
{
    if ( p == 0 )return 1; // If power is 0, then a ^ 0 = 1 for any value of a, And 1 Mod m=1 for any value of m, So return 1
 
    if ( p % 2 ) // If power is odd, Split it : a ^ 5 =( a )* (a ^ 4) --> left and right child respectively.
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m; 
    }
    else //If power is even then split it equally and return the result...
    {
        unsigned int c = bigmod ( a, p / 2, m ); 
        return ( (c%m) * (c%m) ) % m;
    }
}

int main()
{
    unsigned int B, P, M, temp;
    while(!cin.eof()){
        cin >> B >> P >> M;

        cout << "B: " << B << endl;
        cout << "P: " << P << endl;
        cout << "M: " << M << endl;
        


        // unsigned int temp = 1;

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
        // cout << "B: " << B << endl;
        // cout << "P: " << P << endl;
        // cout << "M: " << M << endl;
        // cout << "temp: " << temp << endl;

        // unsigned int result = temp % M;
        // cout << "result: " << result << endl;

        cout << bigmod(B, P, M) << endl;
        cout << "=======" << endl;
    }

    return 0;
}