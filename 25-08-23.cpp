//Triangle
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp)
    {
        if(i==triangle.size()-1)
        {
            return triangle[i][j];
        }
        int d=INT_MAX;
        int di=INT_MAX;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else{
            d=solve(i+1,j,triangle,dp);
            di=solve(i+1,j+1,triangle,dp);
            return dp[i][j]=triangle[i][j]+min(d,di);
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);  
    }
};
