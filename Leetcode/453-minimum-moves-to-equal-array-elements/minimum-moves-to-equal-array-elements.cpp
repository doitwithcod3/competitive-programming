class Solution {
public:
    const int inf = 1e9;
    int minMoves(vector<int>& nums) {
        int sum = 0, n = nums.size();
        int minele = inf;
        for (int ele : nums) {
            minele = min(minele, ele);
            sum += ele;
        }
        sum -= minele * n;
        return sum;
    }
};