#include<bits/stdc++.h>
using namespace std;
int stcheck(int a[],int n,int k){
    if(n==0)
    return -1;
    if(a[0]==k) 
    return 0;
    int index=stcheck(a+1,n-1,k);
    if(index!=-1){
        return index+1;
    }
    return -1;

}
int last(int a[],int n,int k){
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // printf("\n");
    if(n==0){
        return -1;
    }
    int index=last(a+1,n-1,k);
    if(index==-1){
        if(a[0]==k){
            return 0;
        }
        else{
            return -1;
        }
        
    }
    else{
        return index+1;
    }
    
}

int main(){
    int a[]={1,3,7,2,4,9,8,9,0};
     int n = sizeof(a) / sizeof(a[0]);
     int k;
     cout<<"enter:";
     cin>>k;
     cout<<stcheck(a,n,k)<<endl;
     cout<<last(a,n,k)<<endl;
    return 0;
}