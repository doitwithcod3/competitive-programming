// Problem Link : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<int> indices;
        int n = nums.size();
        int maxele = -1e9, minele = 1e9;
        for (auto ele : nums) {
            maxele = max(ele, maxele);
            minele = min(ele, minele);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] == maxele) indices.push_back(i);
            if (nums[i] == minele) indices.push_back(i);
        }

        int ans = 1e9;
        ans = min(ans, max(indices[0], indices[1]) + 1);
        ans = min(ans, n - min(indices[0], indices[1]));
        ans = min(ans, min(indices[0], indices[1]) + 1 + n - max(indices[0], indices[1]));
        return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	
	Solution s;
	auto ans = s.minimumDeletions(a);
	cout << ans << endl;
}
