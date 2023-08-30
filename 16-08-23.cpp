// vertical order traversal of a binary tree

// intuition is same as that of line vise storing but the idea is that if u have same row and same column then u have to sort the element so for that u have to use multiset 
// multiset is the one which store the the in the sorted order and also stores the duplicates also unlike the sets
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            TreeNode*temp=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            m[col][row].insert(temp->val);
            if(temp->left)
            {
                q.push({temp->left,{row+1,col-1}});
            }
            if(temp->right)
            {
                q.push({temp->right,{row+1,col+1}});
            }
        }
        for(auto mp:m)
        {
           auto it=mp.second;
           vector<int>temp;
           for(auto k:it)
           {
               auto l=k.second;
               for(auto p:l)
               {
                   temp.push_back(p);
               }
           }
            ans.push_back(temp);
        }
        return ans;
    }
};
