//LONGEST INCREASING SUBSEQUENCE

// JUST YOU HAVE TO THINK IN TERMS OF DP THAT'S IT
class Solution {
public:
    int lent(int i, vector<int>&nums,vector<int>&dp)
    {
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=1;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]>nums[i])
            {
                ans=max(ans,lent(j,nums,dp)+1);
            }
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,lent(i,nums,dp));
        }
        return ans;
    }
};
