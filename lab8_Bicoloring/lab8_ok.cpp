#include <iostream>
#include <vector>

using namespace std;

void print_nested_vec(vector<vector<int> > & v){
    int size = v.size();
    for (int i = 0; i < size; i++){
        cout << "\nindex i: " << i << endl;
        for (auto it = v[i].begin(); it != v[i].end(); it++){
            cout << *it << " ";
        }
    }
    cout << endl;
}


bool check_color(int node, int color, vector<int> & color_table, vector<vector<int> > & matrix){

    // 檢查這個node有沒有被上色過或是顏色是否相同, 0 代表沒有被上色過
    if (color_table[node] != color && color_table[node] != 0){
        return false;
    } else if (color_table[node] == color){
        // 注意：檢查這點已經被上色過要return回去
        return true;
    }

    // 第一次被走訪以及沒有被上過色的，才會來到這邊
    // 顏色不對或是顏色正確 在上面都會被return回去
    color_table[node] = color;

    // 改成相反顏色
    color = ((color == 1) ? 2 : 1);

    // 走訪他的鄰居
    for (auto it = matrix[node].begin(); it != matrix[node].end(); it++){
        if(!check_color(*it, color, color_table, matrix)){
            return false;
        }
    }

    return true;
}


int main(){
    int n_nodes;
    int n_edges;
    while (cin >> n_nodes){
        if (n_nodes == 0){
            return 0;
        }
        cin >> n_edges;

        vector<int> relation;
        vector<vector<int> > matrix(n_nodes, relation);

        for (int i = 0; i < n_edges; i++){
            int a, b;
            cin >> a >> b;
            matrix[a].push_back(b);
            matrix[b].push_back(a);
        }

        // print_nested_vec(matrix);

        // 0 是沒有上色過, 顏色1 和 顏色2
        vector<int> color_table(n_nodes,0);

        // 從第一個node 0開始, 上色 1
        if(check_color(0, 1, color_table, matrix)){
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }


    }


    return 0;
}