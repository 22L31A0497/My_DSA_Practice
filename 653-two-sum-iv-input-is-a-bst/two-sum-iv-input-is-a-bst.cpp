class Solution {
public:

    void storeInorder(TreeNode* root, vector<int>& inOrder) {
        if(root == NULL) return;

        storeInorder(root->left, inOrder);
        inOrder.push_back(root->val);
        storeInorder(root->right, inOrder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        storeInorder(root, inOrder);

        int start = 0;
        int end = inOrder.size()-1;

        while(start < end) {
            int sum = inOrder[start] + inOrder[end];
            if(sum == k) return true;

            else if (sum < k) {
                start++;
            }

            else if(sum > k) {
                end--;
            }
        }

        return false;
    }
};