// coin change

class Solution {
public:
    int dp[10010];    //created a dp of size 10010. where dp[i] represents minimum number of coins to make the such amount
    int func(int amount,vector<int>&coins)
    {
        if(amount==0)
        {
            return 0;
        }
        if(dp[amount]!=-1)return dp[amount];// if you know the minimum number of coins to make such amount then don't compute again return here only
        int ans=INT_MAX;
        for(auto coin:coins)
        {
            if((amount-coin)>=0)
            {
                ans=min(ans+0LL,func(amount-coin,coins)+1LL);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));   // initializing dp of size 10010 with each index to -1;
        int ans=func(amount,coins);
        return ans==INT_MAX?-1:ans;
    }
};
