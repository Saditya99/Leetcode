/*
Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/
*/

/*
Description:
Convert a Roman numeral to an integer.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    // Map Roman symbols to their values
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;

    // Iterate through the string
    for (int i = 0; i < s.length(); i++) {
        // If current value is less than next value, subtract it
        if (i + 1 < s.length() && romanMap[s[i]] < romanMap[s[i + 1]]) {
            result -= romanMap[s[i]];
        } else {
            // Otherwise, add it
            result += romanMap[s[i]];
        }
    }

    return result;
}

/*
Test:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90, IV = 4

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V = 5, III = 3

Input: s = "IX"
Output: 9

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(1) - constant space
*/