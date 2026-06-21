/*
Problem: Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/
*/

/*
Description:
Find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string.
*/

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> word)
{
    // If array is empty, return empty string
    if (word.empty()) return "";

    int count = 0;

    for (int i = 0; i < word[0].length(); i++)
    {
        char character = word[0][i];

        for (int j = 1; j < word.size(); j++) {

            if (i >= word[j].length() || word[j][i] != character) {
                return word[0].substr(0, count);  // Return prefix up to count
            }

        }
        count++;
    }
    return word[0];  // All strings match the first string
}

/*
Test:
Input: word = ["flower","flow","flight"]
Output: "fl"
Explanation: All strings share the prefix "fl"

Input: word = ["dog","racecar","car"]
Output: ""
Explanation: No common prefix

Time Complexity: O(n * m) where n is number of strings, m is length of prefix
Space Complexity: O(1) - constant space
*/