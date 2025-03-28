#include <bits/stdc++.h>
using namespace std;
class comple
{
    int a, b;

public:
    void set(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void print() { cout << "num is " << a << "+i" << b; }
};
int main()
{
    comple sam;
    sam.set(1, 2);
    sam.print();
    return 0;
}