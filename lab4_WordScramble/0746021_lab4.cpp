#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <typeinfo>

using namespace std;

void print_elem(char elem)
{
    cout << elem;    
}

void print_vec(vector<char> const &input)
{
    cout << " ";
    for_each(input.rbegin(),input.rend(),print_elem);
}

int main()
{
    // char m[50];

    char m[500]; 
    while (cin.getline(m, 500))
    {
        // cout << "\n====\ngetline: " << m << endl; 
        vector<char> arr;
        int j = strlen(m);
        // cout << "j: " << j << endl; 

        for(int i=0; i <= j; i++)
        {
            if (m[i] != ' ' && i != j)
            {
                // cout << "\npush_back m[i]: " << m[i] << endl;
                // cout << "push i: " << i << endl;
                arr.push_back(m[i]);
                // print_vec(arr);
            } else if (m[i] == ' ' | i == j) {
                // cout << "\nhit space m[i]: " << m[i] << endl;
                // cout << "hit i: " << i << endl;
                print_vec(arr);
                arr.clear();
            }
        }
        cout << endl;
    }

    return 0;
}