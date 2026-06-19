/*
Problem: Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/
*/

/*
Description:
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

#include <iostream>
using namespace std;

bool isPalindrome(int x)
{

    if (x < 0)
        return false;

    string s = to_string(x);
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

/*
Test:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Time Complexity: O(n) where n is the number of digits
Space Complexity: O(n) for the string conversion
*/