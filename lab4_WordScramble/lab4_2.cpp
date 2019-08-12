#include<iostream>
#include<vector>
#include<string>

using namespace std;

void print_vec(vector<char> & v){
    // cout << "start printing..." << endl;
    // cout << "v.size(): " << v.size() << endl;
    for (auto it = v.begin(); it !=v.end(); it++){
        // cout << "here" << endl;
        cout << *it;
        // cout << "(int)*it: "<< (int)*it << endl;
    }
    cout << " ";
}

vector<char> reverse_str(vector<char> s){
    // cout << "reverse_str input: ";
    // print_vec(s);
    // cout << endl;
    // if (s.size() == 1){
    //     return s;
    // }
    // 重點！！
    for (int i = 0, j = s.size() - 1; i<=j ;i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    // cout << "reverse_str output: ";
    // print_vec(s);
    // cout << endl;
    return s;
}


int main(){
    string s;
    while(getline(cin, s)){
        // cout << reverse_str(s) << endl;
        vector<char> temp;
        vector<char> reversed;
        char space = ' ';
        for (int i = 0; i < s.size(); i++){
            // 換行符號不知道如何判斷，只好用用size() - 1
            if ((int)s[i] == (int)space || i == s.size()-1){

                // cout << "1. s[i] = " << s[i] << endl;
                if (i == s.size()-1){
                    temp.push_back(s[i]);
                }
                reversed = reverse_str(temp);
                temp.clear();
                print_vec(reversed);
                // cout << reversed << " ";
            } else {
                // cout << "2. s[i] = " << s[i] << endl;
                // cout << "2. (int)s[i] = " << (int)s[i] << endl;
                // cout << "2. (int)space = " << (int)space << endl;
                temp.push_back(s[i]);
                // cout << "2. s[i] = " << s[i] << endl;
            } 
        }
        cout << endl;
    }




    return 0;
}

