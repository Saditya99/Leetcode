/*
Problem: Design Linked List
Link: https://leetcode.com/problems/design-linked-list/
*/

/*
Description:
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
Implement the MyLinkedList class with the following operations.
*/

class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* dummy;
    int size;

public:
    MyLinkedList() {
        dummy = new ListNode(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        ListNode* curr = dummy->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummy->next;
        dummy->next = newNode;
        size++;
    }

    void addAtTail(int val) {
        ListNode* curr = dummy;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new ListNode(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        ListNode* curr = dummy;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        ListNode* newNode = new ListNode(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        ListNode* curr = dummy;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
};

/*
Test:
Input:
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output: [null,null,null,null,2,null,3]
Explanation:
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);    // list: [1]
myLinkedList.addAtTail(3);    // list: [1,3]
myLinkedList.addAtIndex(1,2); // list: [1,2,3]
myLinkedList.get(1);          // return 2
myLinkedList.deleteAtIndex(1);// list: [1,3]
myLinkedList.get(1);          // return 3

Time Complexity: O(n) for get, addAtIndex, deleteAtIndex; O(1) for addAtHead; O(n) for addAtTail
Space Complexity: O(1) - excluding the list itself
*/