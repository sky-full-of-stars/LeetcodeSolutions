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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        
        vector<int> curLevel;
        queue<TreeNode* > q;
        int level = 0;
        q.push(root);
        
        curLevel.push_back(root->val);
        ans.push_back(curLevel);
        curLevel.clear();
        
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();
            if(!top)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                    ans.push_back(curLevel);
                }
                level++;
                curLevel.clear();
                continue;
            }
            if(top->left)
            {
                q.push(top->left);
                curLevel.push_back(top->left->val);
            }  
            if(top->right)
            {
                q.push(top->right);
                curLevel.push_back(top->right->val);
            }
           
        }
        return ans;
    }
};