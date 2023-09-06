// ninja's Training
// memoziation technique
int solve(int day,int ltask,vector<vector<int>>&dp,vector<vector<int>>&points)
{
    if(day==0)
    {
        int mx=0;
        for(int task=0;task<3;task++)
        {
            if(task!=ltask)
            {
                mx=max(mx,points[day][task]);
            }
        }
        return dp[day][ltask]=mx;
    }
    if(dp[day][ltask]!=-1)
    {
        return dp[day][ltask];
    }
    for(int task=0;task<3;task++)
    {
        if(ltask!=task)
        {
            dp[day][ltask]=max(dp[day][ltask],points[day][task]+solve(day-1,task,dp,points));
        }
    }
    return dp[day][ltask];
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    solve(n-1,3,dp,points);
    return dp[n-1][3];
}


// Tabulation
// stack space will get reduced;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int i=1;i<n;i++)
    {
        for(int ltask=0;ltask<4;ltask++)
        {
            dp[i][ltask]=0;
            for(int task=0;task<3;task++)
            {
                if(ltask!=task)
                {
                    dp[i][ltask]=max(dp[i][ltask],dp[i-1][task]+points[i][task]);
                }
            }
        }
    }
    return dp[n-1][3];
}
