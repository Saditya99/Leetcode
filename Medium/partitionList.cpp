/*
Problem: Partition List
Link: https://leetcode.com/problems/partition-list/
*/

/*
Description:
Given the head of a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.
The relative order of nodes in each partition should be preserved.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* newNode = new ListNode(0);

        ListNode* current = newNode;
        ListNode* temp = head;

        while (temp) {
            if (temp->val >= x) {
                temp=temp->next;
                continue;
            }
            ListNode* node = new ListNode(temp->val);
            current->next = node;
            current = current->next;
            temp=temp->next;
        }
        temp = head;
        while (temp) {
            if (temp->val < x) {
                temp=temp->next;
                continue;
            }
            ListNode* node = new ListNode(temp->val);
            current->next = node;
            current = current->next;
            temp=temp->next;
        }
        return newNode->next;
    }
};

/*
Test:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Explanation: Nodes less than 3 (1,2,2) come before nodes >= 3 (4,3,5)

Input: head = [2,1], x = 2
Output: [1,2]

Time Complexity: O(n)
Space Complexity: O(n) - creating new nodes
*/