#include<bits/stdc++.h>
using namespace std;
/*
template <class t1,class t2>



*/
template <class t1,class t2>
class myclass{
    public:
    t1 data1;
    t2 data2;
    myclass(t1 a,t2 b){
        data1=a;
        data2=b;
    }
    void display(){
        cout<<this->data1<<" "<<this->data2<<endl;
    }
};
int main(){
    myclass <int,char>obj(69,'d');
    obj.display();
    return 0;
}