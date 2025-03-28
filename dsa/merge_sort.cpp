#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& a,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int> tmp;
    while(i<=m and j<=e){
        if(a[i]<a[j]){
            tmp.push_back(a[i]);
            i++;   
            }
        else{
            tmp.push_back(a[j]);
            j++;
        }
    }
    while(i<=m){
        tmp.push_back(a[i++]);
    }
    while(j<=e){
        tmp.push_back(a[j++]);
    }
    int k=0;
    for(int i=s; i<=e; i++){
        a[i]=tmp[k++];
    }
    return;
    
}

void mergesort(vector<int>& a, int s,int e){
    if(s>=e) return;
    int mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    return merge(a,s,e);
}

int main(){
    vector<int> a={1,0,4,2,7,9,8,3,5};
    int s=0;
    int e=a.size()-1;
    mergesort(a,s,e);
    for(auto i:a) {
        cout<<i<<" ";
    }
}