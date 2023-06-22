//LOWEST COMMON ANCESTOR OF A BINARY TREE

// INTUITION IS THAT YOU HAVE TO JUST FIND THE PATH TO THE REQUIRED NODES FROM ROOT AND THEN FIND THE LCA
lass Solution {
public:
    bool solve(TreeNode*root,TreeNode*p,vector<TreeNode*>&ans)
    {
        if(root==NULL)
        {
            return false;
        }
        ans.push_back(root);
        if(root->val==p->val)
        {
            return true;
        }
        if(solve(root->left,p,ans)||
        solve(root->right,p,ans))
        {
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root ==NULL)
        {
            return NULL;
        }
        vector<TreeNode*>ans;
        solve(root,p,ans);
        vector<TreeNode*>res;
        solve(root,q,res);
        int i=0;
        int j=0;
        TreeNode*lca;
        while(i<ans.size()&&j<res.size())
        {
            if(ans[i]->val==res[j]->val)
            {
                lca=ans[i];
            }
            i++;j++;
        }
    return lca;
    }
};
