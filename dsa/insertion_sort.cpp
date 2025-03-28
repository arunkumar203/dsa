#include <bits/stdc++.h>
using namespace std;

void insertion(int a[],int n){
    
     for(int i = 1; i < n;i++){
        int c=a[i];
        int p=i-1;
        while(p>=0 and a[p]>c){
            a[p+1]=a[p];
            p--;
        }
        a[p+1]=c;
     }
}
void selection(int a[],int n){
    for(int i=0;i<n;i++){
        int temp_min=i;;
        int j=0;
        for( j=i+1;j<n;j++){
            if(a[j]<a[temp_min]) {
                temp_min=j;
            }
        }
        swap(a[i],a[temp_min]);
        
    }
}

int main() {
    int a[] = {-2,3,4,-1,5,-12,6,1,3,2};
    int n = sizeof(a) / sizeof(a[0]);
    // insertion(a,n);
    selection(a,n);
    for(auto x:a) {
        cout << x <<" ";
    }
    
    
    return 0;
}
