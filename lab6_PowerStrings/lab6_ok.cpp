#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vec(vector<unsigned int> & v){
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


int main(){

    string s;
    string stop = ".";

    while (getline(cin, s)){
        if (s == stop){
            return 0;
        }

        unsigned int str_len = s.size();

        // find factors
        vector<unsigned int> factors;
        for (int i = 1; i <= str_len; i++){
            if (str_len % i == 0){
                factors.push_back(i);
            }
        }
        // print_vec(factors);

        for (auto it = factors.begin(); it != factors.end(); it ++){

            string substr = s.substr(0, *it);
            unsigned int times = str_len / *it;

            string predicted;
            // not allowed..
            // string predicted = substr * times;
            for (int j = 0; j < times; j++){
                predicted += substr;
            }
            // 這個需要嗎？？
            if (it == factors.end() - 1){
                cout << 1 << endl;
                break;
            }

            if (predicted == s){
                // 不是把因數印出來啦...
                cout << times << endl;
                break;
            }


        }


    }


    return 0;
}