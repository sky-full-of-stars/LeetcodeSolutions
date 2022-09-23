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
private:
    bool valid(TreeNode* root, long long mxPermissible, long long mnPermissible)
    {
        if(!root)
            return true;
        return (root->val < mxPermissible and root->val > mnPermissible) and
                valid(root->right, mxPermissible, root->val) and
                valid(root->left, root->val, mnPermissible);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        return valid(root, LLONG_MAX, LLONG_MIN);
    }
};