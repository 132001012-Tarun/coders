// maximum consecutive one' 

// coding ninjas problem 


int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int countZ=0;
    int mxLen=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            countZ++;
        }
        while (countZ > k) {
            if(arr[j]==0)
            {
                countZ--;
                j++;
            }
            else{
                j++;
            }
        }
        mxLen=max(mxLen,i-j+1);
    }
    return mxLen;
}
