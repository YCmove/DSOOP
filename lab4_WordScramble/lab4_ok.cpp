#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<char> reverse(vector<char> & s){
    for (int i = 0, j = s.size()-1 ; i <= j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

void print_char(vector<char> & v){
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *it;
    }
    cout << " ";
}


int main(){
    string s;

    while(getline(cin, s)){
        vector<char> word;
        vector<char> reversed;
        int size = s.size();
        
        for (int i = 0 ; i <= size; i++){

            if(s[i] == ' ' || i == size -1){
                if (i == size -1){
                    word.push_back(s[i]);
                }
                reversed = reverse(word);
                print_char(reversed);
                word.clear();

            } else {
                word.push_back(s[i]);

            }
        }
        cout << endl;
    }



    return 0;
}