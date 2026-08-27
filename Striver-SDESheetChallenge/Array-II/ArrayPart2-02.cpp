/* QuestionLink
	https://leetcode.com/problems/merge-intervals/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        int beg = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (end < intervals[i][0]) {
                result.push_back({beg, end});
                beg = intervals[i][0];
                end = intervals[i][1];
            }
            else end = intervals[i][1];    
        }        
        result.push_back({beg, end});
        return result;
    }
};

// Main for Testing Inputs :) 
int main() { 
	Solution s;
	vector<vector<int>> input;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		input.push_back({a, b});
	}

	vector<vector<int>> result = s.merge(input);

	for (int i = 0; i < result.size(); ++i) {
		cout << result[i][0] << " " << result[i][1] << "\n";
	}

}