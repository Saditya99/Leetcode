/*
Problem: Guess Number Higher or Lower
Link: https://leetcode.com/problems/guess-number-higher-or-lower/
*/

/*
Description:
Guess the number picked by the API using binary search.
*/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Avoid overflow

            int result = guess(mid);

            if (result == 0) {
                return mid;  // Found the number
            } else if (result == -1) {
                high = mid - 1;  // Guess is too high, search left
            } else {  // result == 1
                low = mid + 1;   // Guess is too low, search right
            }
        }

        return -1;  // Should never reach here
    }
};

/*
Test:
Input: n = 10, pick = 6
Output: 6

Time Complexity: O(log n)
Space Complexity: O(1)
*/