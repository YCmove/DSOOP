#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> & v){
    for (auto it = v.begin();it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}




int main(){
    vector<int> primes;
    
    // 注意這邊要先 push 2 進去
    primes.push_back(2);

    // 然後 for loop 從 3 開始找
    for (int i = 3; i < 50000; i++){
        bool prime = true;
        // 最容易忘記的一行
        // j 就是用來 loop over 已有的 primes array, 
        // 只是多加了一個 prime^2 <= i 的條件
        // why?

        // for (int j = 0; j < primes.size(); j++){
        for (int j = 0; j < primes.size() && primes[j]*primes[j] <= i;j++){

            if (i % primes[j] == 0){
                prime = false;
                break;
            }
        }

        if(prime){
            primes.push_back(i);
        }
        if (primes.size() == 10){
            print_vec(primes);
            break;
        }
    }

    vector<int> factors;
    int number = 10;
    // 注意這邊是從 1 開始找
    for (int i=1; i < 10; i++){
        if (number % i == 0){
            factors.push_back(i);
        }
    }

    print_vec(factors);

    


    return 0;
}