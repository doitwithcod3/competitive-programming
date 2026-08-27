// Question Link-
// https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i] - 'a'];
        }
        // for (auto it : freq) cout << it << ' '; cout << endl; 
        
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) return s[i];
        }
        return '$';
       
    }
};

int main() {
    string a; cin >> a;

    Solution s;
    cout << s.nonrepeatingCharacter(a) << endl;
}