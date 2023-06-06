//Minimum number of platforms required
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int ans=1;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0;int j=1;
    	int count=1;
    	while(i<n&&j<n)
    	{
    	   if(dep[i]>=arr[j])
    	   {
    	       count++;
    	       j++;
    	   }
    	   else{
    	       count--;
    	       i++;
    	   }
    	   ans=max(ans,count);
    	}
    	return ans;
    }
};


// job sequence problem
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparision(Job a , Job b)
    {
        return (a.profit > b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
      sort(arr,arr+n,comparision);
      int mx=arr[0].dead;
      for(int i=1;i<n;i++)
      {
          if(arr[i].dead>mx)
          {
              mx=arr[i].dead;
          }
      }
      vector<int>ans(mx+1,-1);
      int sum=0;int jobCount=0;
      for(int i=0;i<n;i++){
          for(int j=arr[i].dead;j>0;j--)
          {
              if(ans[j]==-1)
              {
                  ans[j]=arr[i].id;
                  jobCount++;
                  sum+=arr[i].profit;
                  break;
              }
          }
      }
      vector<int>res;
      res.push_back(jobCount);
      res.push_back(sum);
      return res;
        
    } 
};
