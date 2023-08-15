/*
 * problem link: https://leetcode.com/problems/validate-binary-search-tree
 * */

// * Definition for a binary tree node.
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecursive(root);
    }

private:
    bool isValidBSTRecursive(TreeNode* root, int minAllowed= -2147483648, int maxAllowed = 2147483647){

        // An empty tree is a valid BST
        if(!root) return true;

        bool isRightValid = true;
        bool isLeftValid = true;

        // Make sure root's value is within interval of allowed values
        if(root->val < minAllowed || root->val > maxAllowed){
            return false;
        }

        // if exists a direct child that violates the BST property return false
        // this is meant to avoid [val type] overflow and to avoid unnecessary function calls
        if(root->right && (root->right->val <= root->val)) return false;
        if(root->left && (root->left->val >= root->val)) return false;

        // recursively check if left and right subtrees are valid
        // while taking into consideration narrowing the interval of allowed values
        if(root -> right) isRightValid = isValidBSTRecursive(root->right, root->val + 1, maxAllowed);
        if(root -> left)  isLeftValid = isValidBSTRecursive(root->left, minAllowed, root->val - 1);

        return isRightValid && isLeftValid;
    }
};
