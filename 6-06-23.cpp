//Diameter of a binary tree

class Solution {
public:
    int dfs(TreeNode*root,int height,int&maxdist)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=dfs(root->left,0,maxdist);
        int right=dfs(root->right,0,maxdist);
        if(left+right>maxdist)
        {
            maxdist=left+right;          // max diameter may or may not be passed through root so store the diameter through each node and maximize it
        }
        height++;
        height+=max(left,right);
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdist=0;
        dfs(root,0,maxdist);
        return maxdist;
    }
};
