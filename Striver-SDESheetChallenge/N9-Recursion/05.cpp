/* Problem Link:
    https://leetcode.com/problems/palindrome-partitioning/
*/

#include <bits/stdc++.h>
#define vs vector<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string a, int i, int j) {
        while (i < j) {
            if (a[i] != a[j]) return false;
            i++, j--;
        }
        return true;
    }

    void fun(int par, string s, vs& tmp, vector<vs>& res) {
        if (par == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = par; i < s.size(); ++i) {
            if (isPalindrome(s, par, i)) {
                tmp.push_back(s.substr(par, i-par + 1));
                fun(i + 1, s, tmp, res);
                tmp.pop_back();
            }
        }   
    }

    vector<vector<string>> partition(string s) {
        vector<vs> result;
        vs tmp;
        fun(0, s, tmp, result);
        return result;            
    }
};

int main() {
    string str; cin >> str;
    Solution s;

    auto res = s.partition(str);

    for (auto it : res)
        for (auto i : it) cout << i << " ";
            cout << endl;
}