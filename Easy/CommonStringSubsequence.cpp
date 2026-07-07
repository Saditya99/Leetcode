/*
Problem: Is Subsequence
Link: https://leetcode.com/problems/is-subsequence/
*/

/*
Description:
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string formed by deleting some characters 
without changing the relative order of the remaining characters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        int i=0;
        int j=0;

        while(j<t.length()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
            if(i>=s.length()){
                return true;
            }
        }
    return false;
    }
};

/*
Test:
Input: s = "abc", t = "ahbgdc"
Output: true
Explanation: "abc" is a subsequence of "ahbgdc"
  a h b g d c
  ↑   ↑     ↑
  a   b     c

Input: s = "axc", t = "ahbgdc"
Output: false
Explanation: "axc" is not a subsequence of "ahbgdc"

Input: s = "", t = "ahbgdc"
Output: true
Explanation: Empty string is always a subsequence

Time Complexity: O(n) where n is the length of t
Space Complexity: O(1)
*/
