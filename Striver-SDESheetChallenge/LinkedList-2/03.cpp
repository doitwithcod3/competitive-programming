/* Problem Link:
    https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

void insert(int ele, ListNode* &head) {
    ListNode* node = new ListNode(ele);
    
    if (head == NULL) {
        head = node;
        return;
    }

    ListNode* iter = head;
    while (iter -> next != NULL) {
        iter = iter -> next;
    }
    iter -> next = node;
}

void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL && head -> next == NULL) return head;
        
        ListNode* trav = head;
        int size = 1;
        while (trav -> next != NULL) {
            size++;
            trav = trav -> next;
        }

        ListNode* d = new ListNode(0); d -> next = head;
        ListNode* pre = d;
        ListNode* cur = d;
        ListNode* nex = d;

        while (size >= k) {
            cur = pre -> next;
            nex = cur -> next;

            for (int i = 0; i < k - 1; ++i) {
                cur -> next = nex -> next;
                nex -> next = pre -> next;
                pre -> next = nex;
                nex = cur -> next;
            }
            size -= k;
            pre = cur;
        }
        return d-> next;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode();
    int n, k; cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, head);
    }

    auto result = s.reverseKGroup(head, k);

    display(result);
}
