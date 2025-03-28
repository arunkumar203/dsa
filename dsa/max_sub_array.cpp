#include <bits/stdc++.h>
using namespace std;

void prefixsum(int a[],int n){
  int prefix[n]={0};
  prefix[0]=a[0];
  for(int i=1;i<n;i++){
    prefix[i]=prefix[i-1]+a[i];
  }
  int ls=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int subarraysum=i>0? prefix[j]-prefix[i-1] : prefix[j];
            ls=max(ls,subarraysum);
        }
    }
    cout<<ls<<endl;

}

void kadane(int a[],int n){
    int cs=0,ms=0;
    for(int i=0;i<n;i++){
        cs=cs+a[i];
        if(cs<0){
            cs=0;
        }
        ms=max(ms,cs);
    }
    cout<<ms<<endl;
}

int main() {
    int a[] = {-2,3,4,-1,5,-12,6,1,3,2};
    int n = sizeof(a) / sizeof(a[0]);
    prefixsum(a,n);
    kadane(a,n);
    

    
    return 0;
}
