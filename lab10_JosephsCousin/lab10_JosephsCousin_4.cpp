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

vector<int> gen_primes(int n){
    vector<int> primes;
    primes.push_back(2);

    for (int i=3; i < 50000; i++){
        // 注意: 預設true!
        // bool prime = false;
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j]*primes[j] <= i; j++){

            // 注意
            if (i % primes[j] == 0){
                prime = false;
                break;
            }
        }

        if (prime){
            primes.push_back(i);
        }

        if (primes.size() == n){
            break;
        }
    }
    return primes;
}


int main(){
    int n_person;

    while(cin >> n_person){
        if (n_person == 0){
            return 0;
        }

        vector<int> peoples; // 從 1 開始, 1 殺掉 2 ...
        for (int i = 1; i <= n_person; i++){
            peoples.push_back(i);
        }

        vector<int>::iterator knife = peoples.begin();

        vector<int> primes = gen_primes(n_person - 1);
        // print_vec(primes);



        for (int i = 0; i < primes.size(); i++){
            int size = peoples.size();
            int count = primes[i] % size;
            if (count == 0){
                // 走 size 的步數
                size--; // 注意
                while(size--){
                    if (*knife == peoples.back()){
                        knife = peoples.begin();
                    } else {
                        knife++;
                    }
                }
            } else if(count == 1){
                // 要殺掉自己 do nothing here
                knife;
            } else {
                count--; // 注意
                while(count--){
                    if (*knife == peoples.back()){
                        knife = peoples.begin();
                    } else {
                        knife++;
                    }
                }
            }

            // died, back is necesarry
            int died = *knife;
            int back = peoples.back();
            peoples.erase(knife);
            print_vec(peoples);

            // 要用這兩個來做比較
            if (died == back){
                knife = peoples.begin();
            }
        }
        print_vec(peoples);
    }  
    return 0;
}