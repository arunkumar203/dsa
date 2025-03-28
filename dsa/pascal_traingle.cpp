#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void pascal(int n){
    vector<int> a,b;
    a={1};
    ans.push_back(a);
    while(n--){
        b.push_back(1);
        for(int i=1;i<a.size();i++){
            b.push_back(a[i]+a[i-1]);
        }
        b.push_back(1);
        ans.push_back(b);
        swap(a,b);
        b.clear();
    }
    
    
}
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    pascal(n-1);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}