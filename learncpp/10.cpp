#include <bits/stdc++.h>
using namespace std;
class test{
    int a,b;
    public:
    // test(int i,int j):a(i),b(j) {
    //     cout<<"constructed  called"<<endl;
    // }
    void set(int i,int j){
        a=i;
        b=j;
    }
    void get(){
        cout<<"values are "<<a<<"and "<<b<<endl;
    }
};
int main(){
    // test t(4,5);
    // t.get();
    test t1;
    test t2;
    /*test*t3=&t2;*/   test*t3= new test;
    t1.set(6,9);
    t1.get();
    /* (*t3).set(9,6);*/   t3->set(9,6);
    (*t3).get();
    return 0;
}