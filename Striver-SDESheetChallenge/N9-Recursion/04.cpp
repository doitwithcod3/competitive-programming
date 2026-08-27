/* Problem Link:
    https://leetcode.com/problems/combination-sum-ii/
*/

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

class Solution {
public:

    void fun(int ind, vi& a, vi& temp, vector<vi>& res, int tar) {
        if (tar == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = ind; i < a.size(); ++i) {
            if (i > ind && a[i] == a[i-1]) continue;
            if (tar < a[i]) break;
            
            temp.push_back(a[i]);
            fun(i+1, a, temp, res, tar-a[i]);
            temp.pop_back();
        }
    }

    vector<vi> combinationSum2(vi& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vi> result;
        vi temp;
        fun(0, candidates, temp, result, target);
        return result;        
    }
};

int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Solution s;
    
    auto res = s.combinationSum2(a, target);
    for (auto it : res)
        for (auto i : it) cout << i << " ";
            cout << endl;
}