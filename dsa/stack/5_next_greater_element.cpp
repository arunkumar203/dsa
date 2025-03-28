#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) nge[i] = st.top();
        st.push(nums[i]);
    }
    return nge;
}

int main() {
    vector<int> nums = {6,0,8,1,3};
    vector<int> nge = nextGreaterElement(nums);

    for (int x : nge) cout << x << " ";
    cout<<endl;
    return 0;
}
