/* Problem Link:
    https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return false;

        ListNode* slow = head, *fast = head;

        while (fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next;
            fast = fast -> next;
            slow = slow -> next;

            if (fast == slow) return true;
        }

        return false;

    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode();
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, head);
    }

    ListNode* add = head -> next;
    ListNode* end = head;
    while (end -> next != NULL) end = end -> next;

    end -> next = add;

    cout << s.hasCycle(head) << endl;
}