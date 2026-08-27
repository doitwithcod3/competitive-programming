/* Problem Link:
    https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    int id, dead, profit;
};

class Solution {
public:
    static bool compare(Job a, Job b) {
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        int maxDeadLine = 0;
        for (int i = 0; i < n; ++i) {
            maxDeadLine = max(maxDeadLine, arr[i].dead);
        }
        sort(arr, arr + n, compare);
        vector<int> seq(maxDeadLine, -1);
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead - 1; j >= 0; --j) {
                if (seq[j] == -1) {
                    seq[j] = arr[i].profit;
                    break;
                }
            }
        }
        int job = 0, profit = 0;
        for (int i = 0; i < maxDeadLine; ++i) {
            if (seq[i] != -1) {
                ++job; 
                profit += seq[i]; 
            }
        }
        
        vector<int> res = {job, profit};
        return res;
    } 
};

int main() {
    int n; cin >> n;
    Job arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit; 
    }
    Solution s;
    auto res = s.JobScheduling(arr, n);
    for (auto it : res) cout << it << " "; cout << endl;
}