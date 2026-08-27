/* QuestionLink
	https://leetcode.com/problems/merge-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>&ar2, int n) {
        vector<int> ar1(m);
        for (int i = 0; i < m; ++i) {
            ar1[i] = nums1[i];
        }

        int i = 0, j = 0, index = 0;
        while (i < ar1.size() && j < ar2.size()) {
            if (ar1[i] < ar2[j]) nums1[index++] = ar1[i++];
            else nums1[index++] = ar2[j++];
        }

        while (i < ar1.size()) {
            nums1[index++] = ar1[i++];
        }

        while (j < ar2.size()) {
            nums1[index++] = ar2[j++];
        }

    }
};

// Main for Testing Inputs :) 
int main() { 
	Solution s;
	int m, n; cin >> m >> n;
	vector<int> a(n+m, 0), b(n);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	s.merge(a, m, b, n);
	for (auto it: a) cout << it << " "; cout << endl;
}