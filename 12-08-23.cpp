//Maximum of minimum for every window size

// simple logic only first think of leftsmaller and rightsmaller for any element and the element can be minimum for window size rightsmaller[i]-leftsmaller[i]-1
// so just storing in ans[len] and maximizing it 
]#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int>s;
    vector<int>leftMn(n+1,-1);
    vector<int>rightMn(n+1,n);
    for(int i=0;i<n;i++){
        while(!s.empty()&&a[s.top()]>=a[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            leftMn[i]=s.top();
        }
        s.push(i);
    }  
    while(!s.empty())
    {
        s.pop();
    }
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty()&&a[s.top()]>=a[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            rightMn[i]=s.top();
        }
        s.push(i);
    }  
    vector<int>ans(n+1,INT_MIN);
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        int len=rightMn[i]-leftMn[i]-1;
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);     // for example for window of size k 10 is the minimum then for size k-1 it must be greater than 10 .
    }
    for(int i=1;i<=n;i++)
    {
        res[i-1]=ans[i];
    }
    return res;
}
