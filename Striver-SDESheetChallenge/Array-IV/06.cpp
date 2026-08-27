/* Problem Link:
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> a;
        int i = 0, j = 0;
        int res = 0;
        while (j < s.size()) {
            // cout << i << " " << j << endl;
            if (a.find(s[j]) == a.end()) {
                a.insert(s[j]);
                res = max(res, j - i + 1);
                j++;
            } 
            else {
                a.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string a; cin >> a;

    cout << s.lengthOfLongestSubstring(a) << endl; 
}