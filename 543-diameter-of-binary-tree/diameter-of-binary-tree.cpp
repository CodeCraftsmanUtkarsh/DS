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
    int maxi=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        int temp=f(root);
        return maxi;
    }
    int f(TreeNode* root){
    if(!root){
            return 0;
        }
        int maxLeft=f(root->left);
        int maxRight=f(root->right);
        maxi=max(maxi,(maxLeft+maxRight));
        return max(maxLeft,maxRight) + 1;
    }
};