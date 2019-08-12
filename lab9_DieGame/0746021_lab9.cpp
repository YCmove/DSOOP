#include <iostream>
#include <string>
#include <vector>
// #include <map>
// #include <list>

using namespace std;

    


int main()
{
    int num;


    while(cin >> num){
        if (num == 0){
            return 0;
        }
        // cout << "num: " << num << endl;
        string direction;
        int UP, DOWN, EAST, WEST, SOUTH, NORTH, temp;
        UP=1, DOWN=6, NORTH=2, SOUTH=5, WEST=3, EAST=4;


        for (int i = 0; i < num; i++)
        {
            cin >> direction;
            // cout << "direction:  " << direction << endl;
            
            if (direction == "north"){
                temp = UP;
                UP = SOUTH;
                SOUTH = DOWN;
                DOWN = NORTH;
                NORTH = temp;
            } else if (direction == "south") {
                temp = UP; 
                UP = NORTH; 
                NORTH = DOWN; 
                DOWN = SOUTH; 
                SOUTH = temp;
            } else if (direction == "west") {
                temp = UP; 
                UP = EAST; 
                EAST = DOWN; 
                DOWN = WEST; 
                WEST = temp;
            } else if (direction == "east") {
                temp = UP; 
                UP = WEST; 
                WEST = DOWN; 
                DOWN = EAST; 
                EAST = temp;
            }

        }

        cout << UP << endl;
    }

    return 0;
}