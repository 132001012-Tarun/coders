// validate Binary search tree


// amazing solution yarrr😁. can't even thinked this way🥲

class Solution {
public:
    void inorder(TreeNode*root,vector<int>&nodes)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        vector<int>nodes;
        inorder(root,nodes);
        unordered_map<int,int>mp;
        for(int i=0;i<nodes.size();i++)
        {
            mp[nodes[i]]++;
            if(mp[nodes[i]]==2)
            {
                return false;
            }
        }
        for(int i=0;i<nodes.size()-1;i++)
        {
            if(nodes[i]>nodes[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
