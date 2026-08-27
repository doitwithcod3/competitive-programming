/* Problem Link:
    https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

#include <bits/stdc++.h>
using namespace std;

#define vs vector<string>
#define vi vector<int>
class Solution{
public:   
    void route(int row, int col, string& temp, vs& result, vector<vi>& m, int n, vector<vector<bool>>& v) {
    
        if (row == n-1 && col == n-1) {
            result.push_back(temp);
            return;
        }
        
        // DLRU -> Lex Increasing Order
        if (row+1 < n && m[row+1][col] == 1 && !v[row+1][col]) {
            temp.push_back('D');
            v[row][col] = true;
            route(row+1, col, temp, result, m, n, v);
            v[row][col] = false;
            temp.pop_back();
        }
        if (col>=1 && m[row][col-1] == 1 && !v[row][col-1]) {
            temp.push_back('L');
            v[row][col] = true;
            route(row, col-1, temp, result, m, n, v);
            temp.pop_back();
            v[row][col] = false;
        }
        if (col+1 < n && m[row][col+1] == 1 && !v[row][col+1]) {
            temp.push_back('R');
            v[row][col] = true;
            route(row, col+1, temp, result, m, n, v);
            temp.pop_back();
            v[row][col] = false;
        }
        if (row>=1 && m[row-1][col] == 1 && !v[row-1][col]) {
            temp.push_back('U');
            v[row][col] = true;
            route(row-1, col, temp, result, m, n, v);
            temp.pop_back();
            v[row][col] = false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n));
        string temp;
        vector<string> result;
        if (m[0][0] == 1) route(0, 0, temp, result, m, n, visited);
        return result;
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    vector<vi> maze(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> maze[i][j];
    }
    auto res = s.findPath(maze, n);

    for (auto it : res) cout << it << endl;

}