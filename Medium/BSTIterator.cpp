/*
Problem: Binary Search Tree Iterator
Link: https://leetcode.com/problems/binary-search-tree-iterator/
*/

/*
Description:
Implement the BSTIterator class that represents an iterator over the in-order traversal of a BST.
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

class BSTIterator {
public:
    vector<int> inorder;
    int current = 0;

    void travel(TreeNode* root) {
        if (!root) {
            return;
        }
        travel(root->left);
        inorder.push_back(root->val);
        travel(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        travel(root);
    }
    
    int next() {
        current++;
        return inorder[current - 1];
    }
    
    bool hasNext() {
        if (current >= inorder.size()) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
Test:
Input:
["BSTIterator","next","next","hasNext","next","hasNext"]
[[[7,3,15,null,null,9,20]],[],[],[],[],[]]
Output:
[null,3,7,true,9,false]
Explanation:
BSTIterator bSTIterator = new BSTIterator([7,3,15,null,null,9,20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return False

Time Complexity: O(n) for initialization, O(1) for next() and hasNext()
Space Complexity: O(n) for storing inorder traversal
*/
