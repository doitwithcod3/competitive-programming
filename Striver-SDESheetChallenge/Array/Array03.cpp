/* QuestionLink
	https://leetcode.com/problems/next-permutation/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
  		int partitionIndex = -1;	      
    	for (int i = nums.size() - 2; i >= 0; --i) {
    		if (nums[i] < nums[i+1]) {
    			partitionIndex = i;
    			break;
    		}		
    	}
    	cout << "partitionIndex = " << partitionIndex << endl;
    	if (partitionIndex == -1) {
    		reverse(nums.begin(), nums.end());
    		return;
    	}
    	for (int i = nums.size() - 1; i > partitionIndex; --i) {
    		if (nums[partitionIndex] < nums[i]) {
    			swap(nums[partitionIndex], nums[i]);
    			break;
    		}
    	}
    	reverse(nums.begin() + partitionIndex + 1, nums.end());
    }
};

// Main for Testing Inputs :) 
int main() { 
	Solution s;
	int n; cin >> n;
	vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		cin >> perm[i];
	} 
	s.nextPermutation(perm);

	for (auto it: perm) cout << it << " "; cout << endl;
}
