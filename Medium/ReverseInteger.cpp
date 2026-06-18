/*
Problem: Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/
*/

/*
Description:
Reverse the digits of a 32-bit signed integer. Return 0 if overflow occurs.
*/

#include <iostream>
#include <climits>
using namespace std;

int reverseInteger(int num){

    int answer = 0;

    while(num != 0){

        // Check for overflow before updating answer
        if(answer > INT_MAX/10 || answer < INT_MIN/10){
            return 0;
        }

        int digit = num % 10;
        answer = answer * 10 + digit;
        num /= 10;
    }
    return answer;
}

/*
Test:
Input: num = 123
Output: 321
Explanation: Reverse of 123 is 321

Input: num = -123
Output: -321
Explanation: Reverse of -123 is -321

Time Complexity: O(log n) where n is the number of digits
Space Complexity: O(1)
*/