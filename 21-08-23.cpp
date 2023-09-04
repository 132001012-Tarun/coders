// Frog Jump  (Coding Ninja's)

#include <bits/stdc++.h> 
int solve(int n,vector<int>&heights,vector<int>&dp,int i)
{
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    else{
        dp[i]=min(solve(n,heights,dp,i-1)+abs(heights[i]-heights[i-1]),solve(n,heights,dp,i-2)+abs(heights[i]-heights[i-2]));
    }
    return dp[i];

}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,-1);
    dp[0]=0;
    if(heights.size()==1)
    {
        return 0;
    }
    dp[1]=abs(heights[1]-heights[0]);
    solve(n,heights,dp,n-1);
    return dp[n-1];
}
