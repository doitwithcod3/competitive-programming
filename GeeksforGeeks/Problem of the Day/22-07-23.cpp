// Question Link-
// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data = 0) {
        this -> data = data;
        next = NULL;
    }
};

void insert(int ele, Node* head) {
    if (head == NULL) head = new Node(ele);
    else {
        while (head -> next != NULL) {
            head = head -> next;
        }
        head -> next = new Node(ele);
    }
}
void display(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) {
        if (head == NULL || head -> next == NULL) return head;
        unordered_set<int> hash;
        Node* iter = head;
        hash.insert(head-> data);
        while (iter -> next != NULL) {
            if (hash.find(iter -> next -> data) != hash.end()) {
                iter -> next = iter -> next -> next;
            }
            else {
                hash.insert(iter-> next-> data);
                iter = iter -> next;
            }
        }
        return head;
    }
};

int main() {
    Node* list = new Node(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int ele; cin >> ele;
        insert(ele, list);
    }
    Solution s;
    auto res = s.removeDuplicates(list -> next);

    display(res);
}