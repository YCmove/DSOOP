#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
bool flag;

void dfs(int start, int color, int * colors, vector<int> * graph){ 
     if (colors[start] != 0) { 
        if(!(color == colors[start])){
            flag=false;
        }
     } else {
           colors[start]=color;             
           for(int i = 0; i < graph[start].size(); i++){
                 int color2 = (color == 1) ? 2 : 1;
                 dfs(graph[start][i], color2, colors, graph);
           }
     }
}



int main(){
    /*
    To simplify the problem you can assume:

    • no node will have an edge to itself.
    不會連到自己

    • the graph is nondirected. That is, if a node a is said to be connected to a node b, then you must assume that b is connected to a.
    無向圖

    • the graph will be strongly connected. That is, there will be at least one path from any node to any other node.
    全連接圖

    */

    int n_nodes, n_edges, a, b;

    while(scanf("%d",&n_nodes) && n_nodes){
        scanf("%d",&n_edges);

        vector <int> graph[n_nodes];
        int colors[n_nodes];
        memset(colors, 0, sizeof colors);

        for(int i=0; i < n_edges; i++){
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        flag=true;

        if (n_nodes % 2 == 0)
        {
            flag = true;
            // cout << "n_nodes % 2 == 0" << endl;
        }
        else if (n_edges + 1 == n_nodes)
        {
            flag = true;
            // cout << "n_n_edges + 1 == n_nodes" << endl;
        }
        else if (n_edges == n_nodes)
        {
            flag = false;
            // cout << "n_n_edges == n_nodes" << endl;
        }


        dfs(0,1,colors,graph);

        if(flag){
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }                       
    }

 return 0;   
}