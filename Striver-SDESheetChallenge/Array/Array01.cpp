/* QuestionLink
https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge
*/

#include <bits/stdc++.h>
using namespace std;

void setZ(unordered_set<int> &row, unordered_set<int> &col, vector<vector<int>>& a) {
	// Assigning Zero to all the Elements to a Specific Row
	for (auto it : row) {
		for (int j = 0; j < a[0].size(); ++j) {
			a[it][j] = 0;
		}
	}

	// Assigning Zero to all the Elements to a Specific Column
	for (auto it : col) {
		for (int j = 0; j < a.size(); ++j) {
			a[j][it] = 0;
		}
	} 
}

void setZeros(vector<vector<int>> &a) {
	unordered_set<int> row, col;

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			if (a[i][j] == 0) {
				row.insert(i);
				col.insert(j);
			}
		}
	}
	setZ(row, col, a);
}

// Main for Testing Inputs :) 
int main() { 
	int t; cin >> t;
	while (t--) {
    	vector<vector<int>> input;
		int r, c; cin >> r >> c;
		for (int i = 0; i < r; ++i) {
			vector<int> temp(c);
			for (int j = 0; j < c; ++j) {
				cin >> temp[j];
			}
			input.push_back(temp);
		}

		setZeros(input);

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cout << input[i][j] << " ";
			}
			cout << endl;
		}
	}
}
