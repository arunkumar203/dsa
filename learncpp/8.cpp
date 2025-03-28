#include<bits/stdc++.h>
using namespace std;
class a{
   public:
   void greet(){
    cout<<"hello"<<endl;
   }
};
class b{
    public:
    void greet(){
        cout<<"hello2"<<endl;
    }
};
class c:public a,public b{
    public:
    int d;
    void greet(){
        a::greet(); 
    }
};
int main(){
    a k;
    k.greet();
    b n;
    n.greet();
    c g;
    g.greet();
    return 0;
}