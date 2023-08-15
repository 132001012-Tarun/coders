// Count Inversions

// merge sort only just made small changes in it
#include <bits/stdc++.h> 
int cnt=0;
int merge(long long *arr, int low ,int mid,int high)
{
    vector<int>ans;
    int i=low;
    int j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(arr[j]<arr[i]){
            cnt+=mid-i+1;
            ans.push_back(arr[j]);
            j++;
        }
        else{
            ans.push_back(arr[i]);
            i++;
        }
    }
    while(j<=high)
    {
        ans.push_back(arr[j]);
        j++;
    }
    while(i<=mid)
    {
        ans.push_back(arr[i]);
        i++;
    }
    int t=0;
    for(int k=low;k<=high;k++)
    {
        arr[k]=ans[t];
        t++;
    }
    ans.clear();
    return cnt;
}
void mergeSort(long long *arr, int low,int high){
    if(low>=high){
        return;
    }
    int mid=low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    mergeSort(arr,0,n-1);
    return cnt;
}
