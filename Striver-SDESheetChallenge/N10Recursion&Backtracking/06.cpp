/* Problem Link:
    https://www.codingninjas.com/studio/problems/983635?topList=striver-sde-sheet-problems
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
#define vs vector<string>


bool isValidWord(vs& dict, string&s, int start, int end) {
    for (auto it : dict) {
        if (it == s.substr(start, end-start +1)) return true;
    }
    return false;
}

void fun(int index, string& s, vs &d, string& temp, vs& result) {
    if (index == s.size()) {
        result.push_back(temp);
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        if (isValidWord(d, s, index, i)) {
            temp += s.substr(index, i - index + 1);
            temp.push_back(' ');
            fun(i+1, s, d, temp, result);
            for (int j = 0; j <= i - index + 1; ++j) {
                temp.pop_back();
            }
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &d) {
    string temp;
    vs result;
    fun(0, s, d, temp, result);
    return result;
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<string> d(n);
        for (int i = 0; i < n; ++i) cin >> d[i];
        string a; cin >> a;
        vector<string> result = wordBreak(a, d);
        for (auto it : result) cout << it << endl;
    }
}