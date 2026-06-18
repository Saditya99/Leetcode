/*
Problem: Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

/*
Description:
Find the length of the longest substring without repeating characters.
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> occur;
        int start = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            char current = s[right];

            if (occur.find(current) != occur.end() && occur[current] >= start) {
                start = occur[current] + 1;
            }

            occur[current] = right;
            maxLength = max(maxLength, right - start + 1);
        }

        return maxLength;
    }
};

/*
Test:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(min(m,n)) where m is the size of the character set
*/