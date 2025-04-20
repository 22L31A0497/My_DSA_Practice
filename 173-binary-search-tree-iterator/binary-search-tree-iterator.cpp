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
class BSTIterator {
    // https://youtu.be/D2jMcmxU4bs (take u forward)
    /* TC: O(N), where N = number of nodes in BST */
    /* SC: O(H), H = height of tree, stack space */
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) 
    {
        pushAllLeft(root);
    }
    
    int next() 
    {
        TreeNode *latestNode = st.top();
        st.pop();
        pushAllLeft(latestNode->right);
        return latestNode->val;
    }
    
    bool hasNext() 
    {
        if(st.size() > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void pushAllLeft(TreeNode* root)
    {
        while(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 