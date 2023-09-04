// Minimal Cost

#include <bits/stdc++.h> 
int solve(int n,vector<int>&height,vector<int>&dp,int i,int k)
{
    if(dp[i]!=INT_MAX)
    {
        return dp[i];
    }
    else{
        for(int j=i-1;j>=(i-k)&&j>=0;j--)
        {
            dp[i]=min(dp[i],abs(height[i]-height[j])+solve(n,height,dp,j,k));
        }
    }
    return dp[i];

}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int>dp(n,INT_MAX);
    dp[0]=0;
    if(height.size()==1)
    {
        return 0;
    }
    dp[1]=abs(height[1]-height[0]);
    solve(n,height,dp,n-1,k);
    return dp[n-1];
}
