// Unique Paths II

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        bool k=false;
        bool l=false;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    if(i==0)
                    {
                        k=true;
                    }
                    if(j==0)
                    {
                        l=true;
                    }
                    dp[i][j]=0;
                }
                else if(i==0||j==0)
                {
                    if(k==true&&i==0)
                    {
                        dp[i][j]=0;
                    }
                    else if(l==true&&j==0)
                    {
                        dp[i][j]=0;
                    }
                    else{
                        dp[i][j]=1;
                    }
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
