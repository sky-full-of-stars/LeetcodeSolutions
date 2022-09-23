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
    void maxDepthBFS(TreeNode* root)
    {
        if(!root)
            return;
        
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        int prev = root->val;
        ans.push_back(prev);
        
        while(!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();
            if(!top)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                    ans.push_back(prev);
                }
                continue;
            }
            if(top->left)
            {
                q.push(top->left);
                prev = top->left->val;
            } 
            if(top->right)
            {
                q.push(top->right);
                prev = top->right->val;
            }
             
        }
    }
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) 
    {
        maxDepthBFS(root);
        return ans;
    }
};