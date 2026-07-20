/*
Problem: Find Bottom Left Tree Value
Link: https://leetcode.com/problems/find-bottom-left-tree-value/
*/

/*
Description:
Given the root of a binary tree, return the leftmost value in the last row of the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& result) {
        if (!root) {
            return;
        }

        // If this is the first node we've seen at this level (leftmost)
        if (level == result.size()) {
            result.push_back(root->val);
        }

        // Traverse left first to ensure leftmost is recorded
        dfs(root->left, level + 1, result);
        dfs(root->right, level + 1, result);
    }

    int findBottomLeftValue(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);

        return result.back();  // Last element is the bottom-left value
    }
};

/*
Test:
Input: root = [2,1,3]
Output: 1
Explanation:
    2
   / \
  1   3
Bottom-left value = 1

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
Explanation:
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
Bottom-left value = 7

Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(h) where h is the height of the tree (recursion stack)
*/
