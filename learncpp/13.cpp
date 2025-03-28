#include <bits/stdc++.h>
using namespace std;

class base
{
public:
    int a;
    void display() { cout << "value of a is " << a << endl; }
};
class derived : public base
{
public:
    int b;
    void display()
    {
        cout << "value of a is " << a << endl;
        cout << "b is " << b << endl;
    }
};
int main()
{
    base *b1;
    base b2;
    derived d1;
    derived *d2;
    b1 = &d1;
    b1->a = 69;
    b1->display();
    // b1->b=96;
    d2 = &d1;
    d2->a=1;
    d2->b=2;
    d2->display();


    return 0;
}