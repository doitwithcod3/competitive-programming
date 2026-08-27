/* Problem Link:
    https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = make_pair(end[i], start[i]);
        }
        sort(result.begin(), result.end());
        
        int res = 0, prevMeeting = 0;
        for (int i = 0; i < n; ++i) {
            if (result[i].second > prevMeeting) {
                ++res;
                prevMeeting = result[i].first;
            }
        }
        return res;
        
    }
};

int main() {
    int n; cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; ++i) {
        cin >> start[i] >> end[i];
    }
    Solution s;
    cout << s.maxMeetings(start, end, n) << endl;
}
