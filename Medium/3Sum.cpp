/*
Problem: 3Sum
Link: https://leetcode.com/problems/3sum/
*/

/*
Description:
Find all triplets in the array that sum to zero.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ThreeSum(vector<int> nums, int target)
{
    if (0 == nums.size())
    {
        return {};
    }
    sort(nums.begin(), nums.end());

    vector<vector<int>> answer;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int value = nums[i] + nums[j] + nums[k];

            if (target == value)
            {
                answer.push_back({nums[i], nums[j], nums[k]});

                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;

                j++;
                k--;
            }
            else if (value < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return answer;
}

/*
Test:
Input: nums = [-1,0,1,2,-1,-4], target = 0
Output: [[-1,-1,2],[-1,0,1]]
Explanation: The triplets that sum to 0 are [-1,-1,2] and [-1,0,1]

Input: nums = [0,1,1], target = 0
Output: []
Explanation: No triplets sum to 0

Time Complexity: O(n^2) where n is the length of the array
Space Complexity: O(1) - excluding the space for the answer
*/