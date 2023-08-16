/*
 * Problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * */

#include <vector>
using namespace std;

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sol;
        /*
         * Inorder traversal of a BST yields the elements sorted in ascending order
         * */
        inorderTraversal(root,sol,k);

        return sol[k-1];
    }

private:
    /**
     * @brief Partial inorder traversal of the tree.
     * gets only the smallest k elements.
     *
     * @param root TreeNode to be traversed
     * @param solution reference to vector where numbers would be added.
     * @param k number of smallest elements needed in solution
     * */
    void inorderTraversal(TreeNode* root,vector<int>& solution,int&k){
        if(root){
            inorderTraversal(root->left, solution,k); // traverse left subtree

            // if already got smallest k elements, return
            if(solution.size() == k) return;
            solution.push_back(root->val);
            if(solution.size() == k) return;

            inorderTraversal(root->right,solution,k); // traverse right subtree
        }
    }
};
