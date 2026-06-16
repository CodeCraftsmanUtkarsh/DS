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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n=preorder.size();
        for(int i=1;i<n;i++){
            insert(root, preorder[i]);
        }
        return root;
    }
    void insert(TreeNode* root,int val){
        if(root->val<val){
            if(root->right!=nullptr){
            insert(root->right,val);
            }
            else{
                TreeNode* n=new TreeNode(val);
                root->right=n;
            }
        }
        else{
            if(root->left!=nullptr){
                insert(root->left,val);
            }
            else{
                TreeNode* n=new TreeNode(val);
                root->left=n;
            }
        }
    }
};