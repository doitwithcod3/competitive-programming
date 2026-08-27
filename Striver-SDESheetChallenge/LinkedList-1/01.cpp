/* Problem Link:
    https://leetcode.com/problems/reverse-linked-list/
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

class Solution {
public:

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

    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;

        ListNode* ele = head;
        
        while (ele != NULL) {
            head = head -> next;
            ele -> next = dummy;
            dummy = ele;
            ele = head;
        }
        return dummy;
    }
};

int main() {
    Solution s;
    int n; cin >> n;
    ListNode *head = NULL;

    while (n--) {
        int ele; cin >> ele;
        s.insert(ele, head);
    }

    auto iter = s.reverseList(head);
    s.display(iter);

}
