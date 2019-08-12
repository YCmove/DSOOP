#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Array
{
    public:
        // Array();
        int absolute(int, int);
        void print_arr();
        void push_arr(int);
        int arr_size();
        void push_absarr(int);
        int absarr_size();
        int check_absarr();
        void set_absval(int);

    private:
        vector<int> arr;
        vector<int> absarr;
        int abs_val;
        // long arr[3000];

};

void Array::set_absval(int num)
{
    abs_val = num;
}

void Array::print_arr()
{
    cout << "arr: " << "\n";
    for (int i=0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n----------------------" << "\n";
    cout << "absarr: " << "\n";

    for (int i=0; i < absarr.size(); i++)
    {
        cout << absarr[i] << " ";
    }
}

int Array::absolute(int ind1, int ind2)
{
    long absolute = 0;
    long num1 = arr[ind1];
    long num2 = arr[ind2];
    
    if (num1 > num2)
    {
        absolute = num1 - num2;
    } else {
        absolute = num2 - num1;
    }
    // cout << "num1: " << num1 << " / " << "num2: " << num2 << "\n";
    // cout << "absolute: " << absolute << "\n" << endl;
    return absolute;

}

void Array::push_arr(int num)
{
    arr.push_back(num);
}

void Array::push_absarr(int num)
{
    absarr.push_back(num);
}

int Array::arr_size()
{
    return arr.size();
}

int Array::absarr_size()
{
    return absarr.size();
}

int Array::check_absarr()
{
    int flag = 1;
    int abs_size = absarr_size();

    for (int i=0; i < abs_size; i++)
    {
        // cout << "abs_val: " << abs_val << "\n";
        // cout << "absarr[i]: " << absarr[i] << "\n";
        if (absarr[i] >= abs_val || absarr[i] == 0)
        {
            flag = 0;
            return flag;
        }
        for (int j=0; j < abs_size; j++)
        {
            if (i != j)
            {
                if (absarr[i] == absarr[j])
                {
                    flag = 0;
                    return flag;
                }
            }
        }
    }
    return flag;
}





int main()
{
    long a;
    
    int i = 0;

    while(!cin.eof())
    {
        int n;
        Array c;
        scanf("%d", &n);
        c.set_absval(n);
        // cout << "n : " << n << "\n";

        for (int i =0; i < n;i++)
        {
            cin >> a;
            // cout << a << " " << endl;

            c.push_arr(a);
            int arr_size = c.arr_size();
            // cout << "arr_size: " << arr_size << "\n";

            if (arr_size > 1)
            {
                int abs = c.absolute(arr_size -1, arr_size-2);
                // cout << "abs: " << abs << "\n";
                c.push_absarr(abs);
            }
        }

        if (c.check_absarr() == 1)
        {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
        // c.print_arr();
        // cout << "\nfinal result: " << c.check_absarr() << "\n";
        // cout << "\n======================================\n" << endl;
    }
    return 0;
}