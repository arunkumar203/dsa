#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={9,8,1,2,4,3,67,40,100,232,143};
    int b[300]={0};
    for(int i=0;i<a.size();i++){
        b[a[i]]++;
    }
    for(int i=0,j=0;i<300;i++){
        if(b[i]>0){
            a[j]=i;
            j++;
        }
    }
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}
