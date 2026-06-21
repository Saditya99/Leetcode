/*
Problem: Integer to Roman
Link: https://leetcode.com/problems/integer-to-roman/
*/

/*
Description:
Convert an integer to a Roman numeral.
*/

#include <iostream>
#include <vector>
using namespace std;

string integerToRoman(int num)
{
    // Arrays of Roman numeral symbols and their corresponding values
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string result = "";

    // Iterate through all value-symbol pairs
    for (int i = 0; i < values.size(); i++)
    {
        // While num is greater than or equal to current value
        while (num >= values[i])
        {
            result += symbols[i]; // Append the symbol
            num -= values[i];     // Subtract the value
        }
    }

    return result;
}

/*
Test:
Input: num = 1994
Output: "MCMXCIV"
Explanation: 1000 = M, 900 = CM, 90 = XC, 4 = IV

Input: num = 58
Output: "LVIII"
Explanation: 50 = L, 8 = VIII

Input: num = 9
Output: "IX"

Time Complexity: O(n) where n is the number of Roman numeral symbols
Space Complexity: O(1) - constant space
*/