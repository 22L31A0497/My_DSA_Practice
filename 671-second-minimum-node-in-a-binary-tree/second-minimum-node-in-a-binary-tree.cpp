/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, int firstmini, int &secondmini) {
        // now check for the base case
        if (!root)
            return;
        // check for the value like if node->val is greater than first mini it
        // means it is the second minimum
        if (root->val > firstmini) {
            // but now check the second mini is -1 means we dont have the second
            // mini yet or also check the node->val < secondmini this means
            // either duplicate or we get a smallest value
            if (secondmini == -1 || root->val < secondmini) {
                // update the secondmini
                secondmini = root->val;
            }
        }
        // call for the left
        solve(root->left, firstmini, secondmini);
        // call for the right
        solve(root->right, firstmini, secondmini);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        // lets start building the solution
        // we had a secondmini variable that hold the second min value
        int secondmini = -1;
        // this pass with the first mini value we let it be the root value :
        // assumption
        solve(root, root->val, secondmini);
        // now return the secondmini as the recursive function return it
        return secondmini;
    }
};