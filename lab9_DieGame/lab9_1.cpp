#include <iostream>
#include <string>
#include <vector>
// #include <map>
#include <list>

using namespace std;

class Die{
    public:
    int go_direction(string line){
        if (line == "north"){
            curr1 --;
            cout << "*curr1--> " << *curr1 << endl;
            return *curr1;
        }
        else if (line == "south")
        {
            curr1 ++;
            return *curr1;

        } else if (line == "west") {
            curr2 --;
            return *curr2;

        } else if (line == "east") {
            curr2 ++;
            return *curr2;
        }

    }
    int north;
    int south;
    int west;
    int east;

    // int south_north[4] = {1, 2, 6, 5}; // 往北loop 由南到北
    // int east_west[4] = {1, 3, 6, 4}; //往西loop 由東到西
    // int *curr1 = &south_north[0];
    // int *curr2 = &east_west[0];
};

int main()
{
    int num;
    // vector<vector<int>> die(num+1, vector<int>(4));
    // map<string, string> die;
    // die.insert(pair<string, string>("r000", "student_zero"));
    // list<int> *die = new list<int>[6 + 1];
    // die[1].push_back(2);
    // die[1].push_back(5);
    // die[1].push_back(3);
    // die[1].push_back(4);
    // die[1].push_back(2);

    // die[2].push_back(6);
    // die[2].push_back(1);
    // die[2].push_back(3);
    // die[2].push_back(4);

    // die[3].push_back(2);
    // die[3].push_back(5);
    // die[3].push_back(6);
    // die[3].push_back(1);

    // die[4].push_back(2);
    // die[4].push_back(5);
    // die[4].push_back(1);
    // die[4].push_back(3);

    // die[5].push_back(1);
    // die[5].push_back(6);
    // die[5].push_back(3);
    // die[5].push_back(4);

    // die[6].push_back(5);
    // die[6].push_back(2);
    // die[6].push_back(3);
    // die[6].push_back(4);

    int row = 6 + 1;
    int col = 4 + 1;
    int **die = new int *[row];
    for(int i = 0 ; i < row ; ++i)
    {
        die[i] =new int [col];
        for(int j = 0 ; j < col ; ++j)
        {
            die[i][j]=0;
        }
    }

    die[1][1] = 2; // south
    die[1][2] = 5; // north
    die[1][3] = 3; // east
    die[1][4] = 4; // west

    die[2][1] = 6; // south
    die[2][2] = 1; // north
    die[2][3] = 3; // east
    die[2][4] = 4; // west

    die[3][1] = 2; // east
    die[3][2] = 5;
    die[3][3] = 6;
    die[3][4] = 1;

    die[4][1] = 2;
    die[4][2] = 5;
    die[4][3] = 1;
    die[4][4] = 3;

    die[5][1] = 1; // south
    die[5][2] = 6; // north
    die[5][3] = 3; // east
    die[5][4] = 4; // west

    die[6][1] = 5; // south
    die[6][2] = 2; // north
    die[6][3] = 3; // east
    die[6][4] = 4; // west



    while(cin >> num){
        if (num == 0){
            return 0;
        }
        cout << "num: " << num << endl;
        string direction;
        // Die die;

        int final;
        int curr = 1;

        for (int i = 0; i < num; i++)
        {
            cin >> direction;
            cout << "direction:  " << direction << endl;
            // final = die.go_direction(direction);
            // cout << "final:  " << final << endl;
            // int south_north[4] = {1, 2, 6, 5}; // 往北loop 由南到北
            // int east_west[4] = {1, 3, 6, 4}; //往西loop 由東到西

            
            if (direction == "north"){
                curr = die[curr][2];
            }
            else if (direction == "south")
            {
                curr = die[curr][1];

            } else if (direction == "west") {
                curr = die[curr][4];

            } else if (direction == "east") {
                curr = die[curr][3];
            }
            cout << "temp curr: " << curr << endl;
        }

        cout << "total final: " << curr << endl;
        cout << "==========" << endl;
    }

    return 0;
}