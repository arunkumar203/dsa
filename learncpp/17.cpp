// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
class vector{
    public:
    int *arr;
    int size;
    
    vector(int m){
        size=m;
        arr=new int[size];
    }
    int dot(vector& v){
        int d=0;
        for(int i=0; i<size;i++){
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }

};
int main(){
    vector v1(3);
    v1.arr[0]=1;
    v1.arr[1]=2;
    v1.arr[2]=3;
    vector v2(3);
    v2.arr[0]=4;
    v2.arr[1]=5;
    v2.arr[2]=6;
    int a=v1.dot(v2);
    cout<<a<<endl;
}