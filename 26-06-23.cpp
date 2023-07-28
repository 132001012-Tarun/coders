// Construct a binary tree using preorder and inoreder traversal

//just carefully look at the both the arrays you will get some logic 

// difficult part at this point is to set that recursive function carefully

// intuition is like start iterating in preorder if you found an element in preorder check that 
// element in the inorder. in inorder left of that element is in left subtree and right of that
// element is in right subtree.



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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode*root=construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
    TreeNode*construct(vector<int>&preorder,int prest,int preend,vector<int>&inorder,int inst,int inend,map<int,int>&m)
    {
        if((prest>preend)||(inst>inend))return NULL;
        TreeNode*root=new TreeNode(preorder[prest]);
        int inRoot=m[root->val];
        int nodesleft=inRoot-inst;

        root->left=construct(preorder,prest+1,prest+nodesleft,inorder,inst,inRoot-1,m);
        root->right=construct(preorder,prest+nodesleft+1,preend,inorder,inRoot+1,inend,m);
        return root;
    }
};
