#include<bits/stdc++.h>
using namespace std;
pair<int,int> search(int a[4][4],int n,int m,int k){
    int i=n-1;
    int j=0;
   while(i>=0 and j<=m-1){
    if(a[i][j]==k){
        return {i,j};
    }
    else if(a[i][j]<k){
        j++;

    }
    else{
        i--;
    }
   }
   return {-1,-1};
}
int main(){
    int a[4][4]={{10,20,30,40},
    {15,25,35,45},
    {27,29,37,48},
    {32,33,39,50}};
    int n=4, m=4;
    int k;
    cin>>k;
    // pair<int,int> k=search(a,n,m,33);
    cout<<search(a,n,m,k).first<<" "<<search(a,n,m,k).second<<endl;

}