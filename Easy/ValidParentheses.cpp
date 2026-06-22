/*
Problem: Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/
*/

/*
Description:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            // If it's a closing bracket
            else {
                // If stack is empty or top doesn't match, return false
                if (st.empty() || st.top() != mapping[c]) {
                    return false;
                }
                st.pop();
            }
        }

        // Stack should be empty if all brackets are matched
        return st.empty();
    }
};

/*
Test:
Input: s = "()[]{}"
Output: true

Input: s = "([)]"
Output: false

Input: s = "{[]}"
Output: true

Input: s = "("
Output: false

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(n) for the stack in worst case
*/