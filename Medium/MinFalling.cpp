/*
Problem: Minimum Falling Path Sum
Link: https://leetcode.com/problems/minimum-falling-path-sum/
*/

/*
Description:
Given an n x n matrix of integers, return the minimum sum of any falling path.
A falling path starts at any element in the first row and chooses one element
from the next row that is directly below or diagonally left/right below.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> table(n, vector<int>(n, INT_MAX));
        int minSum = INT_MAX;
        
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, dfs(matrix, table, 0, j, n));
        }
        
        return minSum;
    }
    
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& table, int i, int j, int n) {
        if (j < 0 || j >= n) {
            return INT_MAX;
        }
        
        if (i == n - 1) {
            return matrix[i][j];
        }
        
        if (table[i][j] != INT_MAX) {
            return table[i][j];
        }
        
        int down = dfs(matrix, table, i + 1, j, n);
        int downLeft = dfs(matrix, table, i + 1, j - 1, n);
        int downRight = dfs(matrix, table, i + 1, j + 1, n);
        
        table[i][j] = matrix[i][j] + min(down, min(downLeft, downRight));
        return table[i][j];
    }
};

/*
Test:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: 
  Possible falling paths:
  1 → 5 → 7 = 13
  1 → 4 → 8 = 13
  1 → 5 → 8 = 14
  etc. Minimum is 13.

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: 
  Path: -19 → -40 = -59

Time Complexity: O(n^2) - each cell computed once with memoization
Space Complexity: O(n^2) - memoization table + recursion stack
*/
