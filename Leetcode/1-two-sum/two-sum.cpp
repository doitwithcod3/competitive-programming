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