#include<bits/stdc++.h>
using namespace std;
template <class t1>
class sam{
    t1 a;
    public:
    void display();

};
template <class t1>
void sam<t1>::display(){
    cout<<a;
}
void func(int a){
    cout<<"not a template func"<<endl;
}
template <class t2>
void func(t2 b){
    cout<<"template func"<<endl;
}
int main(){
    func(4);
    return 0;
}