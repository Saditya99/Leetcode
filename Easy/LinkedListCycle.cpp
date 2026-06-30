/*
Problem: Linked List Cycle
Link: https://leetcode.com/problems/linked-list-cycle/
*/

/*
Description:
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached
again by continuously following the next pointer. Return true if there is a cycle,
otherwise return false.
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) 
{
    // If list is empty or has only one node, no cycle
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    ListNode *slow = head;      // Moves one step at a time
    ListNode *fast = head;      // Moves two steps at a time
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow by 1
        fast = fast->next->next;     // Move fast by 2
        
        // If they meet, there's a cycle
        if (slow == fast) {
            return true;
        }
    }
    
    return false;  // Fast reached end, no cycle
}

/*
Test:
Input: head = [3,2,0,-4], pos = 1 (cycle connects to index 1)
Output: true
Explanation: There is a cycle in the linked list where tail connects to the second node

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle where tail connects to the first node

Input: head = [1], pos = -1
Output: false
Explanation: No cycle

Time Complexity: O(n) - Where n is the number of nodes
Space Complexity: O(1) - Only two pointers used
*/
