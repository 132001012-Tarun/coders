//Minimum Falling path sum

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int n=matrix.size();
        if(i==n-1)
        {
            return matrix[i][j];
        }
        int l=INT_MAX;
        int d=INT_MAX;
        int r=INT_MAX;
        if(dp[i][j]!=INT_MIN)
        {
            return dp[i][j];
        }
        if((j-1)>=0)
        {
            l=solve(i+1,j-1,matrix,dp);
        }
        if((j+1)<=(n-1))
        {
            r=solve(i+1,j+1,matrix,dp);
        }
        d=solve(i+1,j,matrix,dp);
        return dp[i][j]=matrix[i][j]+min(l,min(d,r));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int x=solve(0,i,matrix,dp);
            ans=min(ans,x);
        }
        return ans;
    }
};
