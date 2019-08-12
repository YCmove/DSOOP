#include <iostream>
#include <string>

using namespace std;

    


int main()
{
    int num;


    while(cin >> num){
        if (num == 0){
            return 0;
        }

        string direction;
        int temp, up, down, east, west, north, south;
        up = 1;
        down = 6;
        north = 2;
        south = 5;
        west = 3;
        east = 4;
        temp = up;

        for (int i = 0; i < num; i++){
            cin >> direction;

            if (direction == "north"){
                temp = up;
                up = south;
                down = north;
                north = temp; // 重要
                south = down;
                west = west;
                east = east;

            } else if (direction == "south"){
                temp = up;
                up = north;
                down = south;
                north = down;
                south = temp; // 重要
                west = west;
                east = east;
            } else if (direction == "east"){
                temp = up;
                up = west;
                down = east;
                north = north;
                south = south;
                west = down;
                east = temp; // 重要
            } else if (direction == "west"){
                temp = up;
                up = east;
                down = west;
                north = north;
                south = south;
                west = temp; // 重要
                east = down;
            }


        }

        cout << up <<endl;




    }


    return 0;
}