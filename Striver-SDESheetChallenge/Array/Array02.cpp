/* QuestionLink
	https://leetcode.com/problems/pascals-triangle/

Input: numRows = 5

Output: 1
		1 1
		1 2 1
		1 3 3 1
		1 4 6 4 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int nums) {
        vector<vector<int>> result;
        for (int i = 0; i < nums; ++i) {
        	vector<int> temp;
        	if (i == 0) {
        		temp.push_back(1);
        	}
        	else {
				temp.push_back(1);
        		for (int j = 0; j < i - 1; ++j) {
        			temp.push_back(result[i-1][j] + result[i-1][j+1]);
        		}
        		temp.push_back(1);
        	}
        	result.push_back(temp);
        } 
       	return result;
    }
};

// Main for Testing Inputs :) 
int main() { 
	int t; cin >> t;
	while (t--) {
    	Solution s;
    	int n; cin >> n;
    	auto result = s.generate(n);

    	for (int i = 0; i < (int)result.size(); ++i) {
    		for (int j = 0; j < (int)result[i].size(); ++j) {
    			cout << result[i][j] << " ";
    		}
    		cout << endl;
    	}
    	cout << endl;
	}
}
