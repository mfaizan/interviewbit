/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::maxDepth(TreeNode* A) {
    int left = A->left ? maxDepth(A->left) : 0;
    int right = A->right ? maxDepth(A->right) : 0;
    
    return (left > right ? left : right) + 1;
}
