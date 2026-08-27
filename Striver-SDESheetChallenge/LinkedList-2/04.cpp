/* Problem Link:
    https://leetcode.com/problems/palindrome-linked-list/
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

    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL, *nex = NULL;

        while (head != NULL) {
            nex = head -> next;
            head -> next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL && head -> next == NULL) return true;    

        ListNode* slow = head, *fast = head;

        while (fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow -> next = rev(slow -> next);
        slow = slow -> next;

        while (slow != NULL) {
            if (head -> val != slow -> val) return false;
            
            slow = slow -> next;
            head = head -> next;
        }
        return true;
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

    if (s.isPalindrome(head -> next)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}