/* Problem Link:
    https://leetcode.com/problems/4sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j != i + 1 && nums[j] == nums[j-1]) continue;

                long sum = nums[i] + nums[j];
                int a = j + 1, b = nums.size() - 1;
                while (a < b) {
                    long req = (long) target - sum;
                    if (nums[a] + nums[b] < req) a++;
                    else if (nums[a] + nums[b] > req) b--;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[a], nums[b]};
                        result.push_back(temp); a++, b--;
                        while (a < b && nums[a] == nums[a-1]) a++;
                        while (a < b && nums[b] == nums[b+1]) b--;
                    }
                }
            }
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

    auto result = s.fourSum(a, target);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    } 
}