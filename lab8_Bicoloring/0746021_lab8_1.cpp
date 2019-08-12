#include <iostream>
#include <vector>

using namespace std;


void print_nested_vec(const vector<vector<int>> & v){
    int total_node = v.size();
    cout << "total_node: " << total_node << endl;
    for (int i = 0; i < total_node; i++){
        cout << "\nindex: " << i << endl;
        for (auto it = v[i].begin(); it != v[i].end(); it++){
            cout << *it << " ";
        }
        cout << "---------" << endl;
    }
}

bool check_color(int node, int marked_color, vector<vector<int> > & vec, vector<int> color_table){
    // 因為要recursion, 所以先處理當前input node, 再去走訪他的鄰居

    // 先檢查這一點是否有被上色了，以及顏色是否相同
    // color 可以是 0
    if (color_table[node] != marked_color && color_table[node] != 0){
        // 顏色不一樣就爆炸了！！
        // cout << "different color: " << color_table[node] << " and " << marked_color << endl;
        return false;
    } else if (color_table[node] == marked_color){
        // cout << "same color: " << color_table[node] << " and " << marked_color << endl;
        return true;
    }
    // 把這一點上色
    // 此時 node 必為 0 或是 與 marked_color 顏色相同
    color_table[node] = marked_color;

    // 變成相反的顏色
    marked_color = (marked_color == 1 ? 2 : 1);

    // 去走訪相連的點
    vector<int>::iterator it;
    for (it = vec[node].begin(); it != vec[node].end(); it++){
        if(!check_color(*it, marked_color, vec, color_table)){
            return false;
        };
    }
    return true;
}





int main()
{
    /*
    To simplify the problem you can assume:

    • no node will have an edge to itself.
    不會連到自己

    • the graph is nondirected. That is, if a node a is said to be connected to a node b, then you must assume that b is connected to a.
    無向圖

    • the graph will be strongly connected. That is, there will be at least one path from any node to any other node.
    全連接圖

    */

    int n_nodes;
    int n_edges;
    while (cin >> n_nodes)
    {

        bool flag = true;
        cin >> n_edges;

        if (n_nodes == 0)
            return 0;

        // cout << n_nodes << " / " << n_edges << endl;
        vector<int> relation; // 只有在這邊被使用到而已
        vector<vector<int> > vec(n_nodes, relation);
        // 用 vector<vector<int> > 建立點與點之間的關係table

        for (int i = 0 ; i < n_edges; i++){
            int a, b;
            cin >> a >> b;
            // cout << a << " / " << b << endl;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        // print_nested_vec(vec);

        // 顏色表 0代表NULL, 顏色1 和 顏色2
        vector<int> color_table(n_nodes, 0);

        // 從 index 0 th node 開始走訪
        if (check_color(0, 1, vec, color_table))
        {
            cout << "BICOLORABLE." << endl;
        }
        else
        {
            cout << "NOT BICOLORABLE." << endl;
        }
        // cout << "============" << endl;
    }

    return 0;
}