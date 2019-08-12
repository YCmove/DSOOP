#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string line;
    while(getline(cin, line)){

        // cout << "line: " << line << endl;
        vector<char> v;

        // 記得最後一個 dot 要如何處理
        for (int i = 0; i <= line.size(); i++)
        {
            if (line[i] != ' ' && i != line.size()){
                // cout << "line[i] is not space: " << line[i] << endl;
                v.push_back(line[i]);

            } else {

                // cout << "line[i] is space or \\n ! clear vec: " << line[i] << endl;

                vector<char>::reverse_iterator rit = v.rbegin();
                for (rit; rit != v.rend(); rit++){
                    cout << *rit;
                }
                cout << ' ';
                // re-init vector
                v.clear();
            }
        }
        cout << endl;
    }

    return 0;
}