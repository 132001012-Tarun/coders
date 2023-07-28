//kth smallest element in a BST

// always look at the optimized solution whenever a BST is given we can do normally also but 
// whenever bst is there to reduce the complexity and all use mostly inoreder traversal

class Solution {
public:
   void Inorder(TreeNode* root, vector<int>&vec){
        if(root == NULL)
        return;
      Inorder(root->left,vec);
      vec.push_back(root->val);
      Inorder(root->right,vec);
   }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>vec;
        Inorder(root,vec);
        return vec[k-1];
    }
};
