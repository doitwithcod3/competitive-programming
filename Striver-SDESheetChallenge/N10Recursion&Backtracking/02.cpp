/* Problem Link:
    https://leetcode.com/problems/n-queens/
*/

#include <bits/stdc++.h>
using namespace std;

#define vs vector<string>
class Solution {
public:
    bool valid (int row, int col, vector<string>& temp) {
        for (int i = 0; i < row; ++i) {
            if (temp[i][col] == 'Q') return false;
            if (col-i > 0 && temp[row-i-1][col-i-1] == 'Q') return false;
            if (col+i+1 < temp.size() && temp[row-i-1][col+i+1] == 'Q') return false;
        }
        for (int i = 0; i < col; ++i) {
            if (temp[row][i] == 'Q') return false;
        }
        return true;
    }

    void fun(int row, int n, vector<vs>& result, vs& temp) {
        if (row == n) {
            result.push_back(temp);
            return;
        }
        // if i can place queen here .. then i will
        for (int col = 0; col < n; ++col) {
            if (valid(row, col, temp)) {
                temp[row][col] = 'Q';
                fun(row+1, n, result, temp);
                temp[row][col] = '.';
            }
        }
    }   
    vector<vector<string>> solveNQueens(int n) {
        vector<vs> result;
        vs temp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[i] += '.';
            }
        }
        fun(0, n, result, temp);
        return result;    
    }
};

int main() {
    int n; cin >> n;

    Solution s;
    
    auto res = s.solveNQueens(n);
    for (auto it : res) {
        for (auto a : it) cout << a << endl;
        cout << endl << endl;
    }
}