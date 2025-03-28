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
    if(target>=0){
        ds.push_back(a[ind]);
    print(ind , ds, a, n, target - a[ind]);
    ds.pop_back();
    }
    
    print(ind + 1, ds, a, n, target);
}

int main() {
    int a[] = {2,3,6,7};
    vector<int> ds;
    int target = 7;
    print(0, ds, a, 4, target);
}
