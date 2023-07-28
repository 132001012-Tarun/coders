// Convert Sorted Array to Binary Search Tree

//the main point is that make it height balanced
// so the intiuition is that we can use binary search method everything left of the mid will be on left side and right of the mid will be in the right side 

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

    TreeNode* solve(int left,int right,vector<int>&nums)
    {
        if(left>right){
            return nullptr;
        }
        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(left,mid-1,nums);
        root->right=solve(mid+1,right,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};
