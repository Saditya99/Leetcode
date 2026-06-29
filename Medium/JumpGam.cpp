/*
Problem: Jump Game
Link: https://leetcode.com/problems/jump-game/
*/

/*
Description:
You are given an integer array nums. You are initially positioned at the array's first index,
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) 
{
    int farthest = 0;  // Tracks the farthest index we can reach

    for (int i = 0; i < nums.size(); i++) 
    {
        // If current index is beyond our reachable limit, we're stuck
        if (i > farthest) {
            return false;
        }
        
        // Update the farthest we can reach from this position
        farthest = max(farthest, i + nums[i]);
        
        // Early exit: if we can already reach the last index
        if (farthest >= nums.size() - 1) {
            return true;
        }
    }
    
    return true;
}

/*
Test:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0,
which makes it impossible to reach the last index

Input: nums = [0]
Output: true
Explanation: Single element array, already at the last index

Time Complexity: O(n) - Single pass through the array
Space Complexity: O(1) - Constant extra space
*/
