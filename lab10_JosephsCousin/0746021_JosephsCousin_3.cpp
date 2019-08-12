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


int main()
{
    // 先把3502內的 prime number 算出來..
    vector<int> primes;
    primes.push_back(2);
    for(int i=3; i < 50000; i++)
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
            // cout << i << " ";
        }
        if (primes.size() == 3502){
            break;
        }
    }


    int n_person;

    while(cin >> n_person){

        if (n_person == 0){
            return 0;
        }

        vector<int> peoples;
        for (int i = 1; i <= n_person; i++){
            peoples.push_back(i);
        }

        // 現在拿著刀子的人, 從第一人開始
        // int * knife = &peoples[0];
        vector<int>::iterator itknife = peoples.begin();

        // 總共要殺掉n_person-1個人
        for (int i = 0; i < n_person - 1; i++){
            // 第 i th 次使用的prime 為 primes[i]
            // cout << "primes[i] is " << primes[i] << endl;
            int count = primes[i];
            count = count % peoples.size();
            // 重要的是知道count數字的意義
            // 起點有可能是最後一個，或是在中間

            // cout << "[START]    count: " << count << endl;
            // cout << "[START] *itknife: " << *itknife << endl;
            // 走的步數，要包含自己

            if (count == 0){
                // count == 0 時 走 size 的步數
                // cout << "count == 0" << endl;
                int size = peoples.size();
                size --;
                // cout << "size: " << size << endl;
                while (size--){
                    if (*itknife == peoples.back()){
                        // 確認起點是否是最後一個，是的話，跳到vector的第一個
                        // 也算是一步
                        itknife = peoples.begin();
                    } else {
                        itknife ++;
                    }
                }
                // cout << "*itknife: " << *itknife << endl;
            } else if (count == 1){
                // 走一步，就是自己
                // cout << "count == 1" << endl;
                itknife;
                // cout << "*itknife: " << *itknife << endl;
            } else {
                // cout << "count > 1" << endl;
                count --;
                // cout << "count -- count: " << count << endl;
                while (count--){
                    if (*itknife == peoples.back()){
                        itknife = peoples.begin();
                    } else {
                        itknife ++;
                    }
                }
                // cout << "*itknife: " << *itknife << endl;
            }
            

            int died = *itknife;
            int back = peoples.back();
            vector<int>::iterator cut_knife = itknife;
            peoples.erase(cut_knife);
            // cout << "died: " << died << endl;
            // cout << "back: " << back << endl;

            // erase後 只要 itknife 不是最後一個，會自動補位，不需要再++
            if (died == back){
                itknife = peoples.begin();
                // cout << "jump to first final ++ : " << *itknife << endl;
            } 

            // print_vec(peoples);
            // cout << "---------" << endl;
        }
        // cout << "Ans: " << peoples.front() << endl;
        print_vec(peoples);
    }


}