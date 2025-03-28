#include<bits/stdc++.h>
#define line printf("\n");
using namespace std;
int **create(int r,int c){
    int **arr=new int *[r];
    for(int i=0;i<r;i++){
        arr[i]=new int[c];
    }
    int v=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j] =v;
            v++;
        }
    }
    for(int i=0;i<r;i++){
        delete [] arr[i];
    }
    delete [] arr;
    return arr;
    
}
int main(){
    int r,c;
    cout<<"enter:";
    cin>>r>>c;
    int **arr=create(r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        line
    }
    return 0;
}