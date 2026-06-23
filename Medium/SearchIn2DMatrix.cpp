/*
Problem: Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/
*/

/*
Description:
Search for a target value in an m x n integer matrix.
Each row is sorted in ascending order.
The first integer of each row is greater than the last integer of the previous row.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int up = 0;
        int down = matrix.size() - 1;
        int s = matrix[0].size() - 1;

        int start = 0;

        // Step 1: Find which row the target belongs to
        while (up <= down) {
            int m = up + (down - up) / 2;

            if (target >= matrix[m][0] && target <= matrix[m][s]) {
                start = m;
                break;
            } else if (target < matrix[m][0]) {
                down = m - 1;
            } else if (target > matrix[m][s]) {
                up = m + 1;
            }
        }

        // If no row found, target doesn't exist
        if (up > down) {
            return false;
        }

        // Step 2: Binary search within the found row
        int left = 0;
        int right = s;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[start][mid] == target) {
                return true;
            } else if (matrix[start][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

/*
Test:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Time Complexity: O(log(m*n)) where m = rows, n = columns
Space Complexity: O(1)
*/