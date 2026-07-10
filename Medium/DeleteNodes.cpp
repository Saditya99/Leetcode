/*
Problem: Remove Nodes From Linked List
Link: https://leetcode.com/problems/remove-linked-list-elements/
*/

/*
Description:
Remove all nodes from the linked list that have values present in the nums array.
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head || nums.size() == 0) {
            return head;
        }

        unordered_map<int, int> f;
        for (int i = 0; i < nums.size(); i++) {
            f[nums[i]] = 1;
        }

        ListNode* prev;
        ListNode* temp = head;

        // Remove nodes from the beginning if they need to be deleted
        while (f.find(temp->val) != f.end()) {
            head = head->next;
            temp = head;
            if (!temp) {
                return nullptr;
            }
        }

        if (!temp) {
            return temp;
        }
        prev = temp;
        temp = temp->next;

        // Remove nodes from the rest of the list
        while (temp) {
            if (f.find(temp->val) != f.end()) {
                prev->next = temp->next;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

/*
Test:
Input: nums = [1,2,3], head = [1,2,3,4,5]
Output: [4,5]
Explanation: Remove nodes with values 1,2,3

Input: nums = [1], head = [1,2,1,2,1,2]
Output: [2,2,2]
Explanation: Remove all nodes with value 1

Time Complexity: O(n + m) where n is length of list, m is length of nums
Space Complexity: O(m) for the hash map
*/
