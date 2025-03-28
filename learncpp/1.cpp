#include <bits/stdc++.h>
using namespace std;
class employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setdata(int a, int b, int c);
    void getdata()
    {
        cout << "a=" << a << endl;
        cout << "b=" << b << endl;
        cout << "c=" << c << endl;
        cout << "d=" << d << endl;
        cout << "e=" << e << endl;
    }
};

void employee::setdata(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}


int main()
{
    employee sam;
    sam.d = 4;
    sam.e = 5;
    sam.setdata(1, 2, 3);
    sam.getdata();
    return 0;
}