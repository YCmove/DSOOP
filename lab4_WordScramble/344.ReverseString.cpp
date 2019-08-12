#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<char> reverseString(vector<char> s) {

        // SOLUTION 1: inverse print
        // vector<char>::reverse_iterator temp;
        // for (temp = s.rbegin(); temp != s.rend(); ++temp)
        // {
        //     cout << *temp << "";
        // }

        // SOLUTION 2: reverse_iterator
        // vector<char>::reverse_iterator temp;
        // // cout << s.size() << "\n";
        // // cout << &s.back() << "\n";
        // cout << "[";
        // for (temp = s.rbegin(); temp != s.rend(); ++temp)
        // {
        //     cout << "\"" << *temp << "\"" << "";
        //     if (&(*temp) != &s.front()){
        //         cout << ",";
        //     }
        // }
        // cout << "]";

        // 重要
        // SOLUTION 3: O(1) in-line replace
        int i, j;
        for (i = 0, j = s.size() - 1; i <= j; i++, j--)
        {
            char temp =s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};

void print_elem(char elem)
{
    cout << elem;
}
void print_vec(vector<char> c)
{
    for_each(c.begin(), c.end(), print_elem);
}

int main()
{
    Solution s;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    // string str = "hello";
    vector<char> return_vec = s.reverseString(str);
    print_vec(return_vec);
    return 0;
}
