## 直接用 reverse(s.begin(),s.end())

## #include <list>
- `list<int>` 只是 list of int 而已！
- `list<int>* adj = new list<int>[n + 1];` 指向list of int 的pointer


## std::vector iterator (value and address)
- 產生n個空字串的vector: `vector<string> v(n + 1 ,"");` 第一個argv為數量, 第二個才是值
- 連續的物理空間，代表不僅可以用iterator，還可以用offset來access
```
for(vector <unsigned int> :: iterator it = factors.begin(); it != factors.end(); ++it)
{
    // 裡面的值要用 *it 印出來
}
```

```
// 假如有一個陣列長這樣
// len = 5
int arr[] = {1, 2, 3, 4, 5};
int len = sizeof(arr) / sizeof(int);


/*========== 用 index 印出整個陣列 ==========*/

// 很簡單，應該也是大家最常用的方法
for(int i=0 ; i<len ; i++){
    cout << arr[i] << endl;
}


/*========== 用 pointer 印出整個陣列 ==========*/

// begin 指向的是 1 那個位置
// end 指向的是 5 後面沒有東西的那個位置
int *begin = arr + 0;
int *end = arr + len;

int *ptr;
for(ptr=begin ; ptr!=end ; ptr++){
    cout << *ptr << endl;   // 1, 2, 3, 4, 5
}
```

## vector
- vec.front() - 回傳 vector 第一個元素的值。
- vec.back() - 回傳 vector 最尾元素的值。
- vec.push_back() - 新增元素至 vector 的尾端，必要時會進行記憶體配置。
- vec.pop_back() - 刪除 vector 最尾端的元素。不會return 東西回來！
- vec.insert() - 插入一個或多個元素至 vector 內的任意位置。
- v2.insert(v2.begin()+4, L"3");   //在指定位置，例如在第五个元素前插入一个元素
- v2.insert(v2.end(), L"3");   //在末尾插入一个元素
- v2.insert(v2.begin(), L"3");   //在开头插入一个元素
- v2.erase(v2.begin()); //删除开头的元素
- v2.erase(v2.begin(),v2.end); //删除[begin,end]区间的元素
 

## vector 最大與最小元素使用
- [max_element and min_element](https://riptutorial.com/cplusplus/example/11151/find-max-and-min-element-and-respective-index-in-a-vector)
```
std::vector<int> v = {5, 2, 8, 10, 9}; 
int maxElementIndex = std::max_element(v.begin(),v.end()) - v.begin();
int maxElement = *std::max_element(v.begin(), v.end());

int minElementIndex = std::min_element(v.begin(),v.end()) - v.begin();
int minElement = *std::min_element(v.begin(), v.end());

std::cout << "maxElementIndex:" << maxElementIndex << ", maxElement:" << maxElement << '\n';
std::cout << "minElementIndex:" << minElementIndex << ", minElement:" << minElement << '\n';
```


## char 轉 int
- `atoi(argv[3])`


## #include <algorithm>
- print_elem
- print_vec: for_each
- max()、min()、abs()


## #include <math.h> C語言
## #include<cmath> C++
- M_PI 數學pi值
- pow(2, 5) = 2的5次方
- abs(3-7) 絕對值


## #include <string>
```
string s
s.size() // 看字串長度
s.length() // 看字串長度，等同上面
s.at(index) // 拿取某個index的char
s.empty() // 是否為空字串
s.substr(1, 3) // 會拿出index = 1 往後數3個(包含1)
s.find("live")

// string 轉 ASCII, 不需要 4 byte 去 for loop
for (int i = 0; i < line.size(); i++){
    char c;
    c = line.at(i);
    cout << "c: " << c << endl;
    cout << "(int)c: " << (int)c << endl;
}

// 神用法
for (char c:line){
    cout << "c: " << c << endl;
    cout << "(int)c: " << (int)c << endl;
}

```
## 字串處理相關（迴文數或特殊符號）
- `tolower`: 字母改小寫
- `isalnum`: 檢查是否為數字或英文字母

## #include <unordered_map>
- Hash Table 
- 空間換取時間, 可達O(1)
- [document](http://www.cplusplus.com/reference/unordered_map/unordered_map/)
```
    std::unordered_map<int, std::string> map;
    map.insert(std::make_pair(1, "Scala"));
    map.insert(std::make_pair(2, "Haskell"));
    map.insert(std::make_pair(3, "C++"));
    map.insert(std::make_pair(6, "Java"));
    map.insert(std::make_pair(14, "Erlang"));
    std::unordered_map<int, std::string>::iterator it;
    if ((it = map.find(6)) != map.end()) {
        std::cout << it->second << std::endl;
    }
```
- 印出unorder_map
```
for (auto const & pair: unorder_map){
    cout << "key: " << pair.first << " / value: " << pair.second << endl;
}
```


## #include <limit.h>
- `INT_MAX` int的極限
- [各個型別的上下限](https://docs.microsoft.com/zh-tw/cpp/c-language/cpp-integer-limits?view=vs-2019)


## 建立質數表，尋找質數，尋找因數

