// Question Link-
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string FirstNonRepeating(string A){
            int freq[26] = {0};
            queue<char> ones;
            string result;
            for (int i = 0; i < A.size(); ++i) {
                ++freq[A[i] - 'a'];
                
                if (freq[A[i] - 'a'] == 1) ones.push(A[i]);
                while (ones.empty() == false && freq[ones.front() - 'a'] > 1) ones.pop();
                
                if (ones.empty()) result += '#';
                else result += ones.front();
            }
            return result;
        }

};

int main() {
    string a; cin >> a;

    Solution s;
    cout << s.FirstNonRepeating(a) << endl;
}