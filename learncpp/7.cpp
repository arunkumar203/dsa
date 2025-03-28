#include<bits/stdc++.h>
using namespace std;
class employee{
    public:
    int id;
    float salary;
    employee(int i){
        id=i;
        salary=69.9;
    }
    void getid(){
        cout<<"id:"<<id<<"  salary:"<<salary<<endl;
    }
    employee(){}
};
class programmer :public employee{
    public:
    programmer(int j){
        id=j;
    }
    int languageid=5;
    void getdata(){
        cout<<"id:"<<id<<"   language id:"<<languageid<<"  salary:"<<salary<<endl;
    }

};
int main()
{
    employee sam1;
    sam1.id=1;
    sam1.getid();
    employee sam2(2);
    sam2.getid();

    // sam1.id=1,salary=0;
    // sam2.id=2,salary=69.9

    programmer sam3(3);
    sam3.salary=1;
    sam3.getdata();
    cout<<sin(60);


    return 0;
}