// Question Link-
// https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> result;
        while (q.size()) {
            result.push(q.front());
            q.pop();
        }
        
        while (result.size()) {
            q.push(result.top());
            result.pop();
        }
        
        return q;
    }
};

int main() {
    queue<int> q;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        q.push(ele);
    }
    Solution s;
    auto it = s.rev(q);

    while (it.size()) {
        cout << it.front() << " ";
        it.pop();
    }
}