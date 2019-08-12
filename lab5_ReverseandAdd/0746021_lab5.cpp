#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


class Palindrome
{
    public:
        unsigned long counter = 0;
        unsigned long reverse_num(unsigned long x);
        unsigned long plus(unsigned long x, unsigned long y);
        bool checkpali(unsigned long x);
};

unsigned long Palindrome::reverse_num(unsigned long x)
{
    unsigned long remainder = 0;
    unsigned long reversed_number = 0;
    while (x != 0)
    {
        remainder = x % 10;
        reversed_number = reversed_number*10 + remainder;
        x /= 10;
    }
    // cout << "reverseNumber: " << reversed_number << endl;
    return reversed_number;
}

unsigned long Palindrome::plus(unsigned long x, unsigned long y)
{
    unsigned long plused = 0;
    plused = x + y;
    counter++;
    // cout << "plused: " << plused << endl;
    // cout << "counter: " << counter << endl;
    return plused;
}

bool Palindrome::checkpali(unsigned long x)
{
    bool isPali = false;

    unsigned long reverse = reverse_num(x);

    if (reverse == x){
        isPali = true;
    }

    if (isPali){
        cout << counter << " " << x << endl;
        // cout << "counter: " << counter << endl;
        // cout << "x: " << x << endl;
    }
    return isPali;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n; i++)
    {
        Palindrome pali;
        unsigned long num;
        unsigned long reverse_num;
        cin >> num;
        // cout << "num: " << num << endl;
        reverse_num = pali.reverse_num(num);
        num = pali.plus(num, reverse_num);

        while (!pali.checkpali(num))
        {
            // unsigned long reverse_num;
            reverse_num = pali.reverse_num(num);
            num = pali.plus(num, reverse_num);
        }

        // cout << "==========" << endl;
    }
    return 0;
}