class Solution {
public:
    int solve(int sum, TreeNode* root) {
        if (root == nullptr) return 0;

        if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }

        return sum + solve(0, root->left) + solve(0, root->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return solve(0, root);
    }
};
