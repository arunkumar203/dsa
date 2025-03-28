#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& a, int s,int e){
    int pivot=a[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;

}
void quicksort(vector<int>& a, int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);

}
int main(){
    vector<int> a={1,0,4,2,7,9,8,3,5};
    int s=0;
    int e=a.size()-1;
    quicksort(a,s,e);
    for(auto i:a) {
        cout<<i<<" ";
    }
    return 0;
}