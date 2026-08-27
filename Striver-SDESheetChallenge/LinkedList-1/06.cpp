/* Problem Link:
    https://leetcode.com/problems/delete-node-in-a-linked-list/
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
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};

int main() {
    Solution s;
    ListNode *list = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, list);
    }

    ListNode* remove = list -> next -> next;

    s.deleteNode(remove);

    display(list);
    
}