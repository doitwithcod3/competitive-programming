/* Problem Link:
    https://leetcode.com/problems/combination-sum/
*/

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

class Solution {
public:
    void recur(int ind, vi& can, int tar, vector<vi>& res, vi temp) {
        if (ind == can.size() && tar == 0) {
            res.push_back(temp);
            return;
        }
        if (ind == can.size()) return;

        if (tar >= can[ind]) {
            temp.push_back(can[ind]);
            recur(ind, can, tar - can[ind], res, temp);
            temp.pop_back();
        }
        recur(ind+1, can, tar, res, temp);
    }

    vector<vi> combinationSum(vi& candidates, int target) {
        vector<vi> result;
        vi temp;
        recur(0, candidates, target, result, temp);   
        return result;
    }
};

int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    
    auto res = s.combinationSum(a, target);
    for (auto it : res)
        for (auto i : it) cout << i << " ";
            cout << endl;
}