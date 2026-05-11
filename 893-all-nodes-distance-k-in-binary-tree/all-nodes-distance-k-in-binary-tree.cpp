/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,TreeNode*>mp;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        int curr_level=0;
        vis[target]=true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left){
                    mp[n->left->val]=n;
                    q.push(n->left);
                }
                if(n->right){
                    mp[n->right->val]=n;
                    q.push(n->right);
                }
            }
        }
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(curr_level++==k){
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(mp[curr->val] && !vis[mp[curr->val]]){
                    q.push(mp[curr->val]);
                    vis[mp[curr->val]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};