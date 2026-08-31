// Problem Link : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode() : val(0), next(nullptr) {}
 	ListNode(int x) : val(x), next(nullptr) {}
 	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    const int inf = 1e9;
    inline int val(ListNode* temp) { return temp -> val; }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *one = nullptr, *two = nullptr, *three = head;
        vector<int> ans(2, inf);
        int minindex = inf, maxindex = -inf;
        int sequence = 0;
        int prevcritical = -1;
        while(three) {
            if (one && two && three) {
                if ((val(one) < val(two) && val(two) > val(three)) || (val(one) > val(two) && val(two) < val(three))) {
                    minindex = min(minindex, sequence);
                    maxindex = max(maxindex, sequence);
                    if (prevcritical != -1) ans[0] = min(ans[0], sequence - prevcritical);
                    prevcritical = sequence;
                }
            }
            if (two) one = two;
            if (three) two = three;
            three = three -> next;
            sequence++;
        }
        ans[1] = maxindex - minindex;
        if (abs(ans.front()) >= inf || abs(ans.back()) >= inf) ans = {-1, -1};
        return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n; cin >> n;
	ListNode *head = nullptr, *iter = nullptr;
	for (int i = 0; i < n; ++i) {
		int ele; cin >> ele;
		ListNode *node = new ListNode(ele);
		if (head == nullptr) head = node;
		else iter -> next = node;
		iter = node;
	}
	
	Solution s;
	auto ans = s.nodesBetweenCriticalPoints(head);
	cout << ans[0] << " " << ans[1] << endl;
}
