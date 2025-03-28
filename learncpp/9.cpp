#include<bits/stdc++.h>
using namespace std;
class test
{
    int a,b;
    public:
    test(int i,int j):a(i),b(j){
        cout<<"constructor called"<<endl;
        cout<<"values are "<<a<<"and "<<b<<endl;
    }
};
int main(){
    test t(6,9);
    return 0;
}