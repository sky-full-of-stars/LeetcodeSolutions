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
            return -1005;
        
        int leftVal = height(root->left);
        int rightVal = height(root->right);
        
        int includeAll = root->val+leftVal+rightVal;
        int includeRootOnly = root->val;
        int includeRootAndLeft = root->val+leftVal;
        int includeRootAndRight = root->val+rightVal;
        int includeRightOnly = rightVal;
        int includeLeftOnly = leftVal;
        
        int curAns = max(
                         max(
                            max(includeAll,includeRootOnly),
                            max(includeRootAndLeft,includeRootAndRight)   
                            ),
                         max(includeRightOnly, includeLeftOnly)
                        );
        
        dia = max(dia, curAns);
        return max(root->val, root->val + max(leftVal, rightVal));
    }
public:
    int dia = -1002;
    int maxPathSum(TreeNode* root)
    {
        height(root);
        return dia;        
    }
};