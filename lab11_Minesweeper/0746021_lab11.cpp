#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_nested_vec(vector<vector<int> > &v){
    int size = v.size();
    cout << "size: " << size << endl;
    for (int i = 0; i < size; i++){
        cout << "index: " << i << endl;
        for (auto it = v[i].begin() ; it < v[i].end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}

void print_mine(vector<vector<int> > &v){
    int size = v.size();
    int mine = -2; // *
    int safe = -1; // .if (*it == )
    // cout << "size: " << size << endl;
    for (int i = 0; i < size; i++){
        // cout << "index: " << i << endl;
        for (auto it = v[i].begin() ; it < v[i].end(); it++){
            if (*it == mine){
                cout << "*";
            } else {
                cout << *it;
            }
        }
        if (i != size-1){
            cout << endl;
        }
    }
}



int main(){

    int n, m;
    int nth = 1;


    while(cin >> n >> m){
        if (n == 0){
            return 0;
        }

        // 明確知道有幾的char array
        char line[m];

        // 注意這個initial vector of vector (2D-vector)的方法
        vector<int> poi;
        vector<vector<int> > matrix(n, poi);

        

        for(int i = 0; i < n ; i++){
            cin >> line;
            // cout << line << endl;
            for (int j = 0; j < m; j++){
                int temp;
                int mine = 42; // *
                int safe = 46; // .

                if ((int)line[j] == mine){
                    // cout << "it is a mine!" << (int)line[j] << endl;
                    temp = -2;
                } else if ((int)line[j] == safe){
                    // cout << "it is a safe!" << (int)line[j] << endl;
                    temp = -1;
                }
                matrix[i].push_back(temp);
            }
        }
        // print_nested_vec(matrix);
        // return 0;
        // cout << "===== after =====" << endl;

        for(int i = 0; i < n ; i++){
            for (int j = 0; j < m; j++){
                int counter = 0;
                if (matrix[i][j] == -2){
                    continue; // skip mine
                }
                // 4 corner
                if (i == 0 && j == 0){
                    if (matrix[0][j+1] == -2){
                        counter++;
                    }
                    if (matrix[1][j] == -2){
                        counter++;
                    }
                    if (matrix[1][j+1] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }
                if (i == 0 && j == m -1){
                    if (matrix[0][j-1] == -2){
                        counter++;
                    }
                    if (matrix[1][j-1] == -2){
                        counter++;
                    }
                    if (matrix[1][j] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }
                if (i == n-1 && j == 0){
                    if (matrix[i][1] == -2){
                        counter++;
                    }
                    if (matrix[i-1][0] == -2){
                        counter++;
                    }
                    if (matrix[i-1][1] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }
                if (i == n-1 && j == m-1){
                    if (matrix[i][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i-1][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i-1][j] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }

                // 4 corner between line
                if (i == 0 && j != 0 && j != m-1){
                    if (matrix[i][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i][j+1] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j+1] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }
                if (j == 0 && i != 0 && i != n-1){
                    if (matrix[i-1][0] == -2){
                        counter++;
                    }
                    if (matrix[i-1][1] == -2){
                        counter++;
                    }
                    if (matrix[i+1][0] == -2){
                        counter++;
                    }
                    if (matrix[i+1][1] == -2){
                        counter++;
                    }
                    if (matrix[i][j+1] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }
                if (j == m-1 && i != 0 && i != n-1){
                    if (matrix[i-1][j] == -2){
                        counter++;
                    }
                    if (matrix[i-1][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j-1] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }

                if (i == n-1 && j != 0 && j != m-1){
                    if (matrix[i-1][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i-1][j] == -2){
                        counter++;
                    }
                    if (matrix[i-1][j+1] == -2){
                        counter++;
                    }
                    if (matrix[i][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i][j+1] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }



                // all inner point
                if (i != 0 && i != n-1 && j != 0 && j != m -1){
                    if (matrix[i-1][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i-1][j] == -2){
                        counter++;
                    }
                    if (matrix[i-1][j+1] == -2){
                        counter++;
                    }
                    if (matrix[i][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i][j+1] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j-1] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j] == -2){
                        counter++;
                    }
                    if (matrix[i+1][j+1] == -2){
                        counter++;
                    }
                    matrix[i][j] = counter;
                }

            }
        }


        // print_nested_vec(matrix);
        if (nth > 1){
            cout << endl;
        }
        cout << "Field #" << nth << ":" << endl;
        print_mine(matrix);
        
        nth++;
        cout << endl;
        // cout << "============" << endl;
    }





    return 0;
}