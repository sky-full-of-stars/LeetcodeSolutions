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
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        dia = max(dia, 1+leftHeight+rightHeight);
        return 1+max(leftHeight, rightHeight);
    }
public:
    int dia = 0;
    int diameterOfBinaryTree(TreeNode* root)
    {
        height(root);
        return dia-1;        
    }
};