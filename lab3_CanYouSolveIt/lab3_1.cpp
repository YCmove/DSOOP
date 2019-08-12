#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class NodeCount
{
    public:
        long node_count = 0;
        void print(vector<long>, vector<long>);
        void print_origin();
        void create(long, long, long, long);
        long start_moving();
        vector<long> moving(vector<long>);
        vector<long> minus_y_to_0(vector<long>);
        vector<long> x0_jump_to_y0(vector<long>);
        bool check_equal(vector<long>, vector<long>);
        long mathcout();

    private:
        vector<long> sour;
        vector<long> dest;
};

long NodeCount::mathcout()
{
    long k;
    long total_a = sour[0] + sour[1];
    long total_b = dest[0] + dest[1];

    if (total_a == total_b){
        k = dest[0] - sour[0];

    } else if (total_b - total_a == 1){
        k = dest[0] + sour[1];

    } else if (total_b - total_a > 1){
        long j = dest[0] + sour[1];
        long m =(((total_b - total_a - 1)* ((total_a + 1) + (total_b -1)))/2)+(total_b - total_a - 1);
        k = j + m;
    }
    return k;
}

void NodeCount::create(long ax, long ay, long bx, long by)
{
    sour.push_back(ax);
    sour.push_back(ay);
    dest.push_back(bx);
    dest.push_back(by);
}

void NodeCount::print(vector<long> a, vector<long> b)
{
    cout << "a: " << "[" << a[0] << ", " << a[1] << "]" " / " << "b: " << "[" << b[0] << ", " << b[1] << "]\n";
}

void NodeCount::print_origin()
{
    cout << "source: " << "[" << sour[0] << ", " << sour[1] << "]" " / " << "dest: " << "[" << dest[0] << ", " << dest[1] << "]\n";
}

bool NodeCount::check_equal(vector<long> a, vector<long> b)
{
    if (a == b){
        return true;
    }
    return false;
}

long NodeCount::start_moving()
{
    vector<long> node = moving(sour);
    // cout << "start_moving... after moving...\n" << endl;

    // print(node, dest);
    while(!check_equal(node, dest)){
        // cout << "while loop...\n" << endl;
        // print(node, dest);
        node = moving(node);
    }

    return node_count;
}

vector<long> NodeCount::moving(vector<long> node)
{
    if (node[0] == 0 && node[1] == 0){
        // cout << "condition 1:\n" << endl;
        // print(node, dest);
        // [0, 0] -> [0, 1]
        node[1] = 1;
        node_count++;
    }
    else if (node[1] == 0)
    {
        // cout << "condition 2:\n" << endl;
        // print(node, dest);
        // 只有y=0時需要jump
        node = x0_jump_to_y0(node);
    }
    else
    {
        // cout << "condition 3:\n" << endl;
        // print(node, dest);
        // x, y 都不等於零
        node = minus_y_to_0(node);
    }

    // 每步都要檢查
    if (check_equal(node, dest)){
        // cout << "reach the end !! node_count = " << node_count << "\n" << endl;
        // print(node, dest);

    }
    return node;
}

vector<long> NodeCount::minus_y_to_0(vector<long> node)
{
    // cout << "minus_y_to_0\n" << endl;
    node[1]--;
    node[0]++;
    node_count++;
    return node;
}

vector<long> NodeCount::x0_jump_to_y0(vector<long> node)
{
    // cout << "x0_jump_to_y0\n" << endl;
    long temp_x = node[0];
    node[0] = 0;
    node[1] = temp_x + 1;

    node_count++;
    return node;
}



int main()
{
    
    // while (!cin.eof())
    // {
    int n;
    scanf("%d", &n);
    // cout << "total n lines: " << n << "\n";

    for (int i =0; i < n;i++)
    {
        NodeCount t;
        long ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        t.create(ax, ay, bx, by);
        // t.print_origin();
        // long count = t.start_moving();
        long count = t.mathcout();
        cout << "Case " << i + 1 << ": " << count + 1 << "\n";
        // cout << "==================\n" << endl;
    }
    // }
    return 0;
}