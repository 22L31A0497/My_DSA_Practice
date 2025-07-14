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
  void solve(TreeNode* root,string currpath,vector<string>& ans){
    if(root==nullptr){
        return;
    }
    currpath += to_string(root->val);
    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(currpath);
    }
    else{
        currpath+="->";
        solve(root->left,currpath,ans);
        solve(root->right,currpath,ans);
    }
  }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root == nullptr)return ans;
        string currpath;
        solve(root,currpath,ans);
        return ans;
        
    }
};