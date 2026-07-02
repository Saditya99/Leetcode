/*
Problem: Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

/*
Description:
Given a sorted array nums, remove the duplicates in-place such that each element appears only once.
Return the number of unique elements.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int j = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;  // Return the count of unique elements
    }
};

/*
Test:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: The function returns 2, and the first two elements are 1 and 2.

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: The function returns 5, and the first five elements are 0,1,2,3,4.

Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) - in-place modification
*/