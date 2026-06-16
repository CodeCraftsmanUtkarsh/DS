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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        unordered_set<int> s;
        vector<TreeNode*> v;
        v.push_back(root);
        while (v.size() != 0) {
            TreeNode *n = v.back();
            v.pop_back();

            if (n->left)
                v.push_back(n->left);

            if (n->right)
                v.push_back(n->right);
            
            if (s.find(n->val) != s.end())
                return true;

            int x = k - n->val;
            s.insert(x);
        }
        return false;
    }
};