/* Problem Link:
    https://leetcode.com/problems/permutations/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int ind, vector<int>& a, vector<vector<int>>& res) {
        if (ind == a.size()) {
            res.push_back(a);
            return;
        }

        for (int i = ind; i < a.size(); ++i) {
            swap(a[i], a[ind]);
            fun(ind + 1, a, res);
            swap(a[i], a[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        // vector<int> temp;

        fun(0, nums, result);
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    
    auto res = s.permute(a);
    for (auto it : res) {
        for (auto a : it) cout << a << " ";
        cout << endl;
    }
}
