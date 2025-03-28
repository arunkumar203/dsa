//required sum
// 1st method
#include<bits/stdc++.h>
using namespace std;

void print(int ind, vector<int>& ds, int a[], int n, int target) {
    if (ind == n) {
        if (target == 0) {
            for (auto it : ds) 
            cout << it << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(a[ind]);
    print(ind + 1, ds, a, n, target - a[ind]);
    ds.pop_back();
    print(ind + 1, ds, a, n, target);
}

int main() {
    int a[] = {1, 2, 1};
    vector<int> ds;
    int target = 2;
    print(0, ds, a, 3, target);
}

//2nd method
#include<bits/stdc++.h>
using namespace std;
void print(int ind,vector<int>&ds,int a[],int n,int target){
    if(ind==n){
        if(target==0){
            for(auto it:ds)
            cout<<it<<" ";
          cout<<endl;
        
        }
      
        
        return;
    }
    ds.push_back(a[ind]);
    target-=a[ind];
    print(ind+1,ds,a,n,target);
    ds.pop_back();
    target+=a[ind];
    print(ind+1,ds,a,n,target);
    
}
int main(){
    int a[]={1,2,1};
    vector<int> ds;
    print(0,ds,a,3,2);
}
//only any one that satfies required sum
#include<bits/stdc++.h>
using namespace std;
bool print(int ind,vector<int>&ds,int a[],int n,int target){
    if(ind==n){
        if(target==0){
            for(auto it:ds)
            cout<<it<<" ";
            cout<<endl;
            return true;
            }
      
        
        return false;
    }
    ds.push_back(a[ind]);
    target-=a[ind];
    if(print(ind+1,ds,a,n,target)==true){
        return true;
    }
    ds.pop_back();
    target+=a[ind];
    if(print(ind+1,ds,a,n,target)==true){
        return true;
    }
    return false;
    
}
int main(){
    int a[]={1,2,1};
    vector<int> ds;
    print(0,ds,a,3,2);
}

//count total ways

#include<bits/stdc++.h>
using namespace std;
int print(int ind,int a[],int n,vector<int>&ds,int target){
    if(ind==n){
        if(target==0) return 1;
        else return 0;
    }
    ds.push_back(a[ind]);
    int take=print(ind + 1, a, n, ds,target - a[ind]);
    ds.pop_back();
    int not_take=print(ind + 1,a, n, ds,target);
    return take+not_take;
    
}
int main(){
    int a[]={1,2,1};
    int target=2;
    vector<int> ds;
    cout<<print(0,a,3,ds,target);
}