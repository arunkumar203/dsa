#include <bits/stdc++.h>
using namespace std;
vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) pse[i] = st.top();
        st.push(nums[i]);
    }
    return pse;
}

int main() {
    vector<int> nums = {4, 10, 5, 8, 20, 15, 3, 12};
    vector<int> pse = previousSmallerElement(nums);

    for (int x : pse) cout << x << " ";
    cout << endl;
    return 0;
}
