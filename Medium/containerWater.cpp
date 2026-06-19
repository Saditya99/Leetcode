/*
Problem: Container With Most Water
Link: https://leetcode.com/problems/container-with-most-water/
*/

/*
Description:
Given n non-negative integers, find two lines that together with the x-axis form a container that holds the most water.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> nums)
{
    // Initialize two pointers: left at start, right at end
    int left = 0;
    int right = nums.size() - 1;

    // Variable to track the maximum area found so far
    int maxArea = 0;

    // Continue until pointers meet
    while (left < right)
    {
        // Calculate width between the two lines
        int width = right - left;

        // Area = width * height (height is the smaller of the two lines)
        int area = width * min(nums[left], nums[right]);

        // Update maxArea if current area is larger
        maxArea = max(maxArea, area);

        // Move the pointer pointing to the shorter line
        // This gives chance to find a taller line for max area
        if (nums[left] < nums[right])
        {
            left++;  // Move left pointer forward
        }
        else
        {
            right--; // Move right pointer backward
        }
    }

    // Return the maximum area found
    return maxArea;
}

/*
Test:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The max area is between index 1 (8) and index 8 (7): width = 7, height = 7, area = 49

Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) - no extra space used
*/