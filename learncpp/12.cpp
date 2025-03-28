#include<bits/stdc++.h>
using namespace std;
class A{
    int v;
    public:
    // void set(int v){
    A & set(int v){
        this->v = v;
        return *this;
    }
    void get(){
        cout<<"v: "<<v<<endl;
    }

};
int main(){
    A a;
    a.set(2).get();
    a.get();
    return 0;
}