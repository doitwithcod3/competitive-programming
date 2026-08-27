/* Problem Link:
    https://leetcode.com/problems/sudoku-solver/
*/

#include <bits/stdc++.h>
using namespace std;



bool possible = false;
class Solution {
public:

    bool isValid(int row, int col, char ch, vector<vector<char>>& a) {
        for (int i = 0; i < 9; ++i) {
            if (a[i][col] == ch) return false;
            if (a[row][i] == ch) return false;
            if (a[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(i, j, ch, board)) {
                            // cout << "Working for " << i << " " << j << endl;
                            board[i][j] = ch;
                            if (solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        if (solve(board)) possible = true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> a(9, vector<char>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> a[i][j];
        }
    }
    s.solveSudoku(a);
    if (!possible) cout << "Invalid Input for a Sudoko\n";
    else {
        cout << "Solved with Given Solution\n";
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
 
}