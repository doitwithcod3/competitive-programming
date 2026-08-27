/* Problem Link:
    https://leetcode.com/problems/two-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> result;       
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (mp[target - nums[i]] != 0) {
                result.push_back(i);
                result.push_back(mp[target - nums[i]] - 1);
                break;
            }
            else mp[nums[i]] = i+1;
        } 
        
        return result;
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int target; cin >> target;
    auto result = s.twoSum(a, target);

    for (int i = 0; i < (int) result.size(); ++i) cout << result[i] << " "; cout << endl; 

}
