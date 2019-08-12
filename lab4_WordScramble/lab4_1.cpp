#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <typeinfo>

using namespace std;

// class Process
// {
//     public:

//         void print(vector<long>, vector<long>);
//         void print_origin();
//         // void push_arr();
//         // void pop_arr();
//         // vector<long> arr;

// };

// void Process::


// void Process::print(vector<long> a, vector<long> b)
// {
//     cout << "a: " << "[" << a[0] << ", " << a[1] << "]" " / " << "b: " << "[" << b[0] << ", " << b[1] << "]\n";
// }

// void Process::print_origin()
// {
//     cout << "source: " << "[" << sour[0] << ", " << sour[1] << "]" " / " << "dest: " << "[" << dest[0] << ", " << dest[1] << "]\n";
// }

// char * reverse(char* dest, const char* src)
// {
//     int len = strlen(src);
//     int i;
//     for(i = 0; i < len; ++i)
//     {
//         cout << "start: " << endl;

//         dest[len-i-1] = src[i];
//         cout << "dest: " << dest[len-i-1] << endl;
//     }

//     return dest;
// }

void reverse(char *s) {
    int i, j;
    char c;
    // 假設字串長度為n,將0和n-1調換,再換1和n-2,直到字串中間為止
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


  void reverseTokens( char *sentence ) 
  { 
    char *pointers[ 50 ], *temp;
    int count = 0;
    int i;
    int str_len = 0;

    temp = strtok( sentence, " " ); 
    
    while ( temp ) { 
        // pointers[ count-- ] = temp; 
        pointers[ count++ ] = temp;
        cout << "strlen: " << strlen(temp) << endl;
        str_len = strlen(temp);
        char n[str_len];
        strcpy(n, temp);
        temp = strtok(NULL, " ");
    } 
    
    printf( "The tokens in reverse order are:\n" );
    cout << "count: " << count << endl;

    // for ( i = count - 1; i >= 0; i-- ) 

    // vector<long> arr
    for ( i = 0; i < count; i++ )
    {
        // cout << "#" << endl;
        // reverse(pointers[i]);
        // char n[str_len] = temp;
        // n = pointers[i];
        // reverse(n);
        printf("%s#", pointers[i]);
        cout << sizeof(pointers[i]) << endl;
    }
  } 




int main()
{
    
    while (!cin.eof())
    {

        char m[50];
        char d[50];
        char * n[50];
        cin.getline(m, 50);
        cout << "\n====\ngetline: " << m << endl; 
        cout << "strlen: " << strlen(m) << endl;

        reverseTokens(m);

        // cout << "getline sizeof: " << sizeof(m) << endl; 

        // char * pch;
        // printf ("Splitting string \"%s\" into tokens:\n", n);
        // pch = strtok(m, " ");

        // while (pch != NULL)
        // {
        //     printf("%s==",pch);
        //     pch = strtok(NULL, " ");
        // }


    }
    return 0;
}