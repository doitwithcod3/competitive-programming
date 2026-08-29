// Problem Link : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<array<int, 2>> indx(n);
        for (int i = 0; i < n; ++i) {
        	indx[i] = {nums[i], i};
        }
        sort(indx.begin(), indx.end());
        vector<vector<array<int, 2>>> graph = {{indx[0]}};
        for (int i = 1; i < n; ++i) {
        	if (indx[i][0] - graph.back().back().front() <= limit) graph.back().push_back(indx[i]);
        	else graph.push_back({indx[i]});
        }
        
        vector<int> ans(n);
        for (auto it: graph) {
        	vector<int> indices;
        	for (auto &[ele, index] : it) indices.push_back(index);
        	sort(indices.begin(), indices.end());
        	for (int i = 0; i < indices.size(); ++i) {
        		ans[indices[i]] = it[i][0];
        	}
        }
        return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	int limit; cin >> limit;
	
	Solution s;
	auto ans = s.lexicographicallySmallestArray(a, limit);
	for (auto it: ans) cout << it << " "; cout << endl;
}
