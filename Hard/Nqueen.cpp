/*
Problem: N-Queens
Link: https://leetcode.com/problems/n-queens/
*/

/*
Description:
Place N queens on an N x N chessboard so that no two queens attack each other.
Return all possible solutions.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<int, int> diagonal1;
    unordered_map<int, int> diagonal2;
    vector<int> column;
    vector<vector<int>> positions;  // Stores queen positions for each solution

    void forwardCheck(vector<int>& result, int n, int row) {
        if (row >= n) {
            positions.push_back(result);  // Store the solution
            return;
        }

        for (int i = 0; i < n; i++) {
            // Check if column and diagonals are free
            if (column[i] == -1 &&
                diagonal1.find(row - i) == diagonal1.end() &&
                diagonal2.find(row + i) == diagonal2.end()) {

                // Place queen
                column[i] = 1;
                diagonal1[row - i] = 1;
                diagonal2[row + i] = 1;
                result.push_back(i);

                // Recurse to next row
                forwardCheck(result, n, row + 1);

                // Backtrack
                result.pop_back();
                column[i] = -1;
                diagonal1.erase(row - i);
                diagonal2.erase(row + i);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Initialize column array
        column.assign(n, -1);

        vector<int> result;
        positions.clear();

        // Find all queen placements
        forwardCheck(result, n, 0);

        // Convert positions to board representation
        vector<vector<string>> answer;
        for (auto& pos : positions) {
            vector<string> board;
            for (int col : pos) {
                string row(n, '.');
                row[col] = 'Q';
                board.push_back(row);
            }
            answer.push_back(board);
        }
        return answer;
    }
};

/*
Test:
Input: n = 4
Output: [
 [".Q..","...Q","Q...","..Q."],
 ["..Q.","Q...","...Q",".Q.."]
]
Explanation: There are 2 distinct solutions for 4-Queens

Input: n = 1
Output: [["Q"]]

Time Complexity: O(N!) where N is the number of queens
Space Complexity: O(N^2) for the board
*/