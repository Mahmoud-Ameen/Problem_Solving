/*
 * Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * */

#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto node = root;
        while(node){
            // if both nodes are greater than current node,
            // their LCA must be in the right subtree
            if(p->val > node->val && q->val > node->val)
                node = node->right;
            // if both nodes are less than current node,
            // their LCA must be in the left subtree
            else if(p->val < node->val && q->val < node->val)
                node = node->left;
            // if one is equal to current node or
            // one is greater and the other is smaller, current node is their LCA
            else
                return node;
        }

        return node;
    }
};