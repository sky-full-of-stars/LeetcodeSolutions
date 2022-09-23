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
    TreeNode* assistBuildTree(vector<int> &preorder,vector<int> &inorder,int &cur,int lo,int hi)
    {
        if(lo > hi)
            return NULL;
        
        int rootVal = preorder[cur];
        TreeNode* root = new TreeNode(rootVal);
        
        //nice time to use pass by reference
        cur++;
        root->left =  assistBuildTree(preorder, inorder, cur, lo, inOrderPos[rootVal]-1);
        root->right=  assistBuildTree(preorder, inorder, cur, inOrderPos[rootVal]+1, hi); 
        return root;
    }
    
public:
    map<int,int> inOrderPos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i=0;i<inorder.size(); i++)
            inOrderPos[inorder[i]] = i;
        
        int rootIdx = 0;
        return assistBuildTree(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
};