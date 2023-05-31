// N meetings in one room 
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int,int>a[n+1];
        for(int i=0;i<n;i++)
        {
            a[i].first=end[i];
            a[i].second=i;
        }
        sort(a,a+n);//sorting based on first term of pairs
        int end_time=a[0].first;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(start[a[i].second]>end_time)
            {
                count++;
                end_time=a[i].first;
            }
        }
        return count;
    }
};
