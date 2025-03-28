#include <iostream>
using namespace std;
class Complex;
class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    int sumRealComplex(Complex, Complex);
};

class Complex
{
private:
    int a, b;
    friend int Calculator ::sumRealComplex(Complex o1, Complex o2);
    friend class Calculator;

public:
    void setNumber(int n1, int n2);
    void getNumber(void);
} x, y;

void Complex ::setNumber(int n1, int n2)
{
    a = n1;
    b = n2;
}

void Complex ::getNumber(void)
{
    cout << "The generated Complex number is " << a << " +"
         << " " << b << "i"
         << "." << endl;
}

int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int main()
{
    x.setNumber(4, 5);
    x.getNumber();
    y.setNumber(9, 7);
    y.getNumber();
    Calculator o;
    int reslt = o.add(2, 3);
    cout << reslt << endl;
    int cplxSum = o.sumRealComplex(x, y);
    cout << cplxSum << endl;
    cout << " " << endl;
    return 0;
}

// https: // www.gstatic.com/og/_/js/k=og.qtm.en_US.W-89OXWW37Q.2019.O/rt=j/m=qgl,q_dnp,q_pc,qmd,qcwid,qbd,qapid/exm=qaaw,qabr,qadd,qaid,qalo,qebr,qein,qhaw,qhawgm3,qhba,qhbr,qhbrgm3,qhch,qhchgm3,qhga,qhid,qhidgm3,qhin,qhlo,qhlogm3,qhmn,qhpc,qhsf,qhsfgm3,qhtt/d=1/ed=1/rs=AA2YrTv6vp7JTA69x6O6B3q1MLRwtPb_5A