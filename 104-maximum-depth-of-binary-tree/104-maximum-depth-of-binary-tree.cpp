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
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        
        queue<TreeNode* > q;
        int level = 0;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();
            if(!top)
            {
                if(!q.empty())
                    q.push(NULL);
                level++;
                continue;
            }
            if(top->right)
            {
                q.push(top->right);
            }
            if(top->left)
            {
                q.push(top->left);
            }  
        }
        return level;
    }
};