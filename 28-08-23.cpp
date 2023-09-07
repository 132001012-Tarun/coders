//Partition equal subset sum
// intution is like if total sum is even then only you can partition the array into two subsets of equal sum then 
// why don't you think of like passing total_sum/2 is the target you have to find the subset contains this sum 

class Solution {
public:
bool solve(vector<int>&arr,int k,int i,vector<vector<int>>&dp)
{
    if(k==0){
        return true;
    }
    if(k<0||i==arr.size())
    {
        return false;
    }
    if(dp[i][k]!=-1)
    {
        return dp[i][k];
    }
    bool pick=solve(arr,k-arr[i],i+1,dp);
    bool not_pick=solve(arr,k,i+1,dp);
    return dp[i][k]=pick||not_pick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(arr,k,0,dp);
}
    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            total_sum+=nums[i];
        }
        if(total_sum%2==0)
        {
            return subsetSumToK(nums.size(),total_sum/2,nums);
        }
        else{
            return false;
        } 
    }
};
