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
 int findPathSum(TreeNode* root ,int &maxi){
    if(root == nullptr)return 0;
    int lmp = max(0,findPathSum(root->left,maxi));
    int rmp = max(0,findPathSum(root->right,maxi));
    maxi = max(maxi,lmp+rmp+root->val);
    return max(lmp,rmp)+root->val;
 }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findPathSum(root,maxi);
        return maxi;
        
    }
};