#include<bits/stdc++.h>
using namespace std;
int issorted(int a[],int n){
  if(n==1 or n==0) 
  return true;
  if(a[0]<a[1] and issorted(a+1,n-1)){
    return true;
  }
  return false;
}
int main(){
    int a[]={1,2,3,4,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<issorted(a,n);

    return 0;
}