class Solution {
public:

    void f(TreeNode* root, int k, int& count, TreeNode*& n) {
        if (!root) {
            return;
        }

        f(root->left, k, count, n);

        count++;

        if (count == k) {
            n = root;
            return;
        }

        f(root->right, k, count, n);
    }

    int kthSmallest(TreeNode* root, int k) {

        int count = 0;
        TreeNode* n = nullptr;

        f(root, k, count, n);

        return n->val;
    }
};