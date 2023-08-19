// Find Minimum Number Of Coins


vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int>ans{1,2,5,10,20,50,100,500,1000};
    vector<int>res;
    int sum=0;
    for(int i=8;i>=0;i--)
    {
        sum+=ans[i];
        if(sum>n)
        {
            sum=sum-ans[i];
            continue;
        }
        res.push_back(ans[i]);
        while(sum<=n)
        {
            if(sum==n)
            {
                return res;
            }
            else{
                sum+=ans[i];
                if(sum<=n)
                res.push_back(ans[i]);
            }
        }
        sum=sum-ans[i];
    }
    return res;
}
