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
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        if(maxDepth(root)<1){
            return false;
        }
        else{
            return true;
        }
    }
    int maxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int maxLeft=maxDepth(root->left);
        int maxRight=maxDepth(root->right);
        if(abs(maxLeft-maxRight)>1){
            return -50000;
        }
        return max(maxLeft,maxRight)+1;
    }

};