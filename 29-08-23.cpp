// Binary Tree Maximum Path Sum

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
    int ans=-1e9;
    int solve(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        int curr_val=root->val;
        root->val=max(root->val,max(curr_val+right,curr_val+left));
        ans=max(max(ans,root->val),curr_val+left+right);
        return root->val;
    }
    int maxPathSum(TreeNode* root) {
        int res=solve(root);
        return max(res,ans);
    }
};
