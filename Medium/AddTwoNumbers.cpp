/*
Problem: Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/
*/

/*
Description:
Add two numbers represented as linked lists. Return sum as linked list.
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int value)
    {
        data = value;
        next = NULL;
    }
};

ListNode *AddTwoNumbers(ListNode *node1, ListNode *node2)
{

    ListNode *answer = new ListNode(0);

    int carryValue = 0;
    int sum = 0;

    while (node1 != NULL || node2 != NULL || carryValue > 0)
    {
        sum = carryValue;

        if (node1 != NULL)
        {
            sum += node1->data;
            node1 = node1->next;
        }

        if (node2 != NULL)
        {
            sum += node2->data;
            node2 = node2->next;
        }

        carryValue = sum / 10;
        sum = sum % 10;
        answer->next = new ListNode(sum);
        answer = answer->next;
    }
    return answer;
}

/*
Test:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807
*/