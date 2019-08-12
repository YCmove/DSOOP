#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
    // char m[1000000];
    string s;

    string end = ".";

    while(getline(cin, s))
    {
        if (s == end)
        {
            return 0;
        }
        // cout << "origin string s: " << s << endl;

        unsigned int str_len = s.length();
        vector<unsigned int> factors;


        // 求因數
        // 先算出這個字串長度，可能有的因數
        for (int i=1;i<=str_len;i++) 
        {        
            if (str_len % i==0) 
                factors.push_back(i);
        } 

        // cout << endl;
        unsigned int str_length = s.length();


        for(vector <unsigned int> :: iterator it = factors.begin(); it != factors.end(); ++it){
            // cout << "factors: " << *it << endl;

            string sub_str = s.substr(0, *it);
            unsigned int cur_factor = *it;
            // cout << "sub_str: " << sub_str << endl;
            // cout << "str_length: " << str_length << endl;
            // cout << "cur_factor: " << cur_factor << endl;

            string predicted_str;
            unsigned int n_times = str_length / cur_factor;
            // cout << "n_times: " << n_times << endl;

            for (int j = 0; j < n_times;j++)
            {
                predicted_str += sub_str;
            }
            // cout << "final predicted_str: " << predicted_str << endl;

            if (predicted_str == s)
            {
                cout << n_times << endl;
                // cout << "answer: " << n_times << endl;
                // cout << "predicted is true!!!" << endl;
                // cout << "=========" << endl;
                break;
            }

            // 最後一個因數，代表此題沒有任何的power string(只有自己本身)
            if (it == factors.end() - 1)
            {
                cout << 1 << endl;
                // cout << "end is 1" << endl;
            }
            // cout << "=========" << endl;

        }




    }
    
    return 0;
}