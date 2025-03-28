#include<bits/stdc++.h>
using namespace std;
template <class t>
void swapp(t &a,t &b){
    t temp=a;
    a=b;
    b=temp;

}
int main(){
    int x=69,y=96;
    swapp(x,y);
    cout<<"x= "<<x<<" y= "<<y<<endl;
    return 0;
}