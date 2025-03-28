#include<bits/stdc++.h>
using namespace std;
class store{
  int id,price;
  public:
  void setdata(int a,int b){
    id=a;
    price=b;
  }
  void getdata();
};
void store::getdata(){
    cout<<"id is "<<id<<"price is "<<price<<endl;
}
int main(){
    store *s =new store[3];
    store *s1=s;

    int p,q;
    for(int i=0;i<3;i++){
        cout<<"enter id and price";
        cin>>p>>q;
        s->setdata(p,q);
        s++;

    }
    s=s1;
    for(int i=0;i<3;i++){
        s->getdata();
        s++;

    }

    return 0;
}