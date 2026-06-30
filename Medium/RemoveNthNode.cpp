/*
Problem: Remove Nth Node From End of List
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

/*
Description:
Remove the nth node from the end of a linked list and return its head.
*/

#include <iostream>
using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n == 0) return head;

        ListNode* temp = head;

        while (n > 1 && temp->next) {
            temp = temp->next;
            n--;
        }

        if (!temp->next) return head;

        temp->next = temp->next->next;
        return head;
    }
};

/*
Test:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,4,5]
Explanation: Remove the 2nd node from end (node with value 4)

Input: head = [1], n = 1
Output: [1]
Explanation: n is out of bounds, nothing deleted

Input: head = [1,2], n = 1
Output: [1]
Explanation: Remove the last node (2)

Time Complexity: O(n)
Space Complexity: O(1)
*/