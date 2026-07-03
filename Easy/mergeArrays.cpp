/*
Problem: Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
*/

/*
Description:
Merge two sorted arrays nums1 and nums2 into nums1 as one sorted array.
nums1 has size m+n, where the first m elements are valid and the rest are zeros.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;

        // Compare elements from both arrays and add smaller one
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1
        while (i < m) {
            result.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        // Copy result back to nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = result[k];
        }
    }
};

/*
Test:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: Merge [1,2,3] and [2,5,6] into nums1

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: nums2 is empty, nums1 remains unchanged

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: nums1 is empty, copy nums2 to nums1

Time Complexity: O(m+n)
Space Complexity: O(m+n) for the result array
*/