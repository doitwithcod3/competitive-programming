class Solution {
public:
    const int inf = 1e9;
    bool uniformArray(vector<int>& nums) {
        bool sameparity = true;
        int smallestodd = inf, smallesteven = inf;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) smallesteven = min(smallesteven, nums[i]);
            else smallestodd = min(smallestodd, nums[i]);
            if (i > 0 && (nums[i - 1] % 2) != (nums[i] % 2)) sameparity = false; 
        }
        return (sameparity || smallestodd < smallesteven);
    }
};