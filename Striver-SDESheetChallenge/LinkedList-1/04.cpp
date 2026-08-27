/* Problem Link:
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode();
        temp -> next = head;

        ListNode *fast = temp, *slow = temp;

        while (n--) {
            fast = fast -> next;
        }

        while (fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        // cout << slow -> val << endl;
        slow -> next = slow -> next -> next;

        return temp -> next;
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

    int k; cin >> k;

    auto it = s.removeNthFromEnd(list, k);

    display(it);
    
}