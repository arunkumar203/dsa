#include<bits/stdc++.h>
using namespace std;
class constr
{
    public:
    int a;
    constr()
    {
        a=0;
        cout<<"inside the constructor"<<endl;
    }
    ~constr()
    {
        cout<<"inside the destructor"<<endl;
    }
};
int main(){
   constr b;
   return 0;

}