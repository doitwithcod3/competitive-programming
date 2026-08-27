/* QuestionLink
	https://leetcode.com/problems/rotate-image/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		// Transpose the Matrix
		for (int i = 0; i < (int) matrix.size(); ++i) {
			for (int j = 0; j <= i; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		// Reversing each Row
		for (int i = 0; i < (int) matrix.size(); ++i) {
			reverse(matrix[i].begin(), matrix[i].end());
		} 
    }
};

// Main for Testing Inputs :) 
int main() { 
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int> (n));
	for (int i = 0; i < (int) a.size(); ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			cin >> a[i][j];
		}
	}
	Solution s;
	s.rotate(a);
	for (int i = 0; i < (int) a.size(); ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
