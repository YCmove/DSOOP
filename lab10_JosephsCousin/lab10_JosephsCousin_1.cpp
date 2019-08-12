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

vector<int> make_primes(int n){
    vector<int> primes;
    primes.push_back(2);
    // cout << "what??" << endl;
    for(int i=3; i < n; i++)
    {
        bool prime=true;
        for(int j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
        {
            if(i % primes[j] == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime) 
        {
            primes.push_back(i);
            cout << i << " ";
        }
    }
    return primes;
}



int main()
{
    // 先把3502內的 prime number 算出來..
    // vector<int> primes;
    // primes.push_back(2);
    // for(int i=3; i < 3502; i++)
    // {
    //     bool prime=true;
    //     for(int j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
    //     {
    //         if(i % primes[j] == 0)
    //         {
    //             prime=false;
    //             break;
    //         }
    //     }
    //     if(prime) 
    //     {
    //         primes.push_back(i);
    //         // cout << i << " ";
    //     }
    // }


    int n_person;

    while(cin >> n_person){

        if (n_person == 0){
            return 0;
        }
        vector<int> primes = make_primes(n_person);
        vector<int> peoples;
        for (int i = 1; i <= n_person; i++){
            peoples.push_back(i);
        }

        // 現在拿著刀子的人, 從第一人開始
        int * knife = &peoples[0];
        vector<int>::iterator itknife = peoples.begin();

        // 總共要殺掉n_person-1個人
        for (int i = 0; i < n_person - 1; i++){
            // 第 i th 次使用的prime 為 primes[i]
            // cout << "primes[i] is " << primes[i] << endl;
            int count = primes[i];

            while (--count){
                // cout << "##### start at *itknife: " << *itknife << endl;
                // cout << "count: " << count << endl;
                // 總共執行count-1次, 因為要包含自己開始數
                // if (*knife == peoples.back() && count == 1){
                if (*itknife == peoples.back()){
                    // cout << "1. last one" << endl;
                    itknife = peoples.begin();
                    // cout << "1. *itknife: " << *itknife << endl;
                } else {
                    itknife++;
                    // cout << "2. *itknife: " << *itknife << endl;
                }
                // cout << "3. *itknife: " << *itknife << endl;
            }

            // peoples.erase(remove(peoples.begin(), peoples.end(), (char*)(*knife)), peoples.end());
            // int died = *knife;
            // cout << "died: " << died << endl;
            // cout << "kill this *itknife: " << *itknife << endl;
            int died = *itknife;
            int back = peoples.back();
            vector<int>::iterator cut_knife = itknife;
            peoples.erase(cut_knife);

            // cout << "died: " << died << endl;
            if (died == back){
                itknife = peoples.begin();
            }

            // 殺掉拿到刀子的人之後，傳給下一個人
            // knife++;

            // print_vec(peoples);
            // cout << "---------" << endl;
        }
        cout << peoples.front() << endl;
    }
    // print_vec(peoples);


}