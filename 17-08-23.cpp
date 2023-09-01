// LCA 

// intution is like find the path from root to the both nodes and store the path of each in a vector and find then find the latest common node

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode*root,TreeNode*p,vector<TreeNode*>&v)
    {
        if(root==NULL)
        {
            return false;
        }
        v.push_back(root);
        if(root==p)
        {
           return true;
        }
        if(solve(root->left,p,v)||
        solve(root->right,p,v)){
            return true;
        }
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||p==NULL||q==NULL)
        {
            return NULL;
        }
        if(root==p||q==root)
        {
            return root;
        }
        vector<TreeNode*>v;
        solve(root,p,v);
        vector<TreeNode*>ans;
        solve(root,q,ans);
        int i=0;int j=0;
        TreeNode*res;
        while(i<v.size()&&j<ans.size())
        {
            if(v[i]==ans[j])
            {
               res=v[i];
            }
            i++;j++;
        }
        return res;
    }
};
