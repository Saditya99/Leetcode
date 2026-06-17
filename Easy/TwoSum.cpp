/*
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
*/

/*
Description:
Find two numbers in array that add up to target. Return their indices.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store number and its index
        unordered_map<int, int> compliments;

        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement needed
            int value = target - nums[i];

            // Check if complement exists in map
            if (compliments.find(value) != compliments.end()) {
                // Return the indices of complement and current number
                return {compliments[value], i};
            }

            compliments[nums[i]] = i;
        }

        // Return empty if solution doesn't exist
        return {};
    }
};

/*
Test:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] == 9, so we return [0, 1]

Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
*/