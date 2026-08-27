/* Problem Link:
    https://leetcode.com/problems/subsets-ii/
*/

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

class Solution {
public:

    void subset(int ind, vi& temp, vi& nums, vector<vi>& res) {
        if (ind == nums.size()) return;
        
        res.push_back(temp);

        for (int i = ind+1; i < nums.size(); ++i) {
            if (i != ind+1 && nums[i-1] == nums[i]) continue;
            
            temp.push_back(nums[i]);
            subset(i, temp, nums, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        subset(-1, temp, nums, result);
        return result;
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    
    auto res = s.subsetsWithDup(a);
    for (auto it : res)
        for (auto i : it) cout << i << " ";
            cout << endl;
}