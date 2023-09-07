// subset sum equal to k

#include <bits/stdc++.h> 
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
