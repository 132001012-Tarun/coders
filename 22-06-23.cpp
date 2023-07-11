//SUBSETS


class Solution {
public:
   void findSub(vector<vector<int>>&res,vector<int>&v,vector<int>nums,int i){
        res.push_back(v);
        if(i==nums.size())
        {
            return ;
        }
        for(int j=i;j<nums.size();j++)
        {
            v.push_back(nums[j]);
            findSub(res,v,nums,j+1);
            v.pop_back();
        }
       return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        findSub(res,v,nums,0);
        return res;
    }
};// JUST CONSTRUCT A TREE YOU WILL GET IDEA OF THIS BACKTRACKING 
