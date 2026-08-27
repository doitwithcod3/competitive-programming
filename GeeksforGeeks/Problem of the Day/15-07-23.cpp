// Question Link-
// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int n)
    {
        int del = n/2;
        vector<int> store;
        while (del--) {
            store.push_back(s.top());
            s.pop();
        }
        s.pop();
        for (int i = store.size() - 1; i >= 0; --i) {
            s.push(store[i]);
        }
    }
};

int main() {
    stack<int> a;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        a.push(ele);
    }
    
    Solution s;
    s.deleteMid(a, n);

    while(a.size()) {
        cout << a.top() << " ";
        a.pop();
    }
}