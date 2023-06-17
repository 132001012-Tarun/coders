//Lowest common ancestor of a binary search tree.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL ||root==p||root==q)
        {
            return root;
        }
        TreeNode*left= lowestCommonAncestor(root->left,p,q);
        TreeNode*right= lowestCommonAncestor(root->right,p,q);
        if(left==NULL)
        {
            return right;
        }
        else if(right==NULL)
        {
            return left;
        }
        else{
            return root;
        }
    }
};


// if binary searrch tree is not given then think of this logic 

//find the path from root to the both nodes and compare the last common node

// here is the code implementation
int par[v]// for storing the parent of child v 
  void dfs(int v,int p=-1){
  par[v]=p;
  for(int child:g[v]){
    if(child==par)continue;
    dfs(child,v);
  }
}
vector<int>path(int v){
  vector<int>ans;
  while(v!=-1){
    ans.push_back(v);
    v=par(v);
  }reverse(ans.begin(),ans.end());
  return ans;
}
