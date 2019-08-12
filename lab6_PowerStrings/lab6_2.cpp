#include <iostream>
#include <string>
#include <vector>

using namespace std;


void print_vec(vector<int> & v){
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}



int main(){
    string s;
    string stop = ".";

    while(getline(cin, s)){
        if (s == stop){
            return 0;
        }

        int size = s.size();

        // 找因數
        vector<int> factors;
        for(int i = 1; i <= size; i++){
            if (size % i == 0){
                factors.push_back(i);
            }
        }
        // print_vec(factors);

        for (auto it = factors.begin(); it != factors.end(); it++){
            // cout << "==========" << endl;
            // 注意，從index 0 數來(包含index 0本身) 共取幾個char
            string sub_str = s.substr(0, *it);
            string predicted = sub_str;
            
            // cout << "factor *it: " << *it << endl;
            // cout << "sub_str: " << sub_str << endl;
            int times = size / *it;
            for (int i = 0; i < times - 1; i++){
                predicted += sub_str;
            }
            cout << "predicted: " << predicted << endl;

            // cout << "factors.size(): " << factors.size() << endl;

            if (it == factors.end()-1){
            // if (times == size){
                // cout << "here?" << endl;
                cout << 1 << endl;
                break;
            }

            if (predicted == s){
                cout << times << endl;
                break;
            }

        }



    }
    return 0;
}