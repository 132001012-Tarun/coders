// SUBSET SUMS GeeksForGeeks


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>&arr,int l,int r,vector<int>&ans,int sum)
    {
    if(l>r)
    {
        ans.push_back(sum);   
        return;
    }
    solve(arr,l+1,r,ans,sum+arr[l]);    // including the current element
    solve(arr,l+1,r,ans,sum);     // excluding the current element
    return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int sum=0;
        vector<int>ans;
        solve(arr,0,N-1,ans,sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
