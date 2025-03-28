#include <bits/stdc++.h>
using namespace std;
void sub(int ind,int n,vector<int>&ds,vector<int>&a){
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(a[ind]);
    sub(ind+1,3,ds,a);
    ds.pop_back();
    sub(ind+1,3,ds,a);
}
int main()
{
    // cout<<"Hello World";
    vector<int> a={1,2,3};
    vector<int> ds;
    sub(0,3,ds,a);
    

    return 0;
}

