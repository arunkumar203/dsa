#include<bits/stdc++.h>
using namespace std;
void sort1(int a[],int n){
   if(n==1)
   return;
   for(int i=0; i<n-1; i++){
    if(a[i]>a[i+1]){
        swap(a[i],a[i+1]);
    }
   }
   sort1(a,n-1);
}
void sort2(int a[],int n,int j){
    if(n==0 || n==1)
    return;
    if(j==n-1){
        sort2(a,n-1,0);
        return ;
    }
    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    sort2(a,n,j+1);


}
int main(){
    int a[]={-2,-3,0,12,3,2,1,-5,15,20};
    int n=sizeof(a)/sizeof(a[0]);
    // sort1(a,n);
    sort2(a,n,0);

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
        }

    return 0;
}