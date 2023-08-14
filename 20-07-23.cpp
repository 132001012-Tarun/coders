//SubArray With Given Xor

// intuition is observation only 

int Solution::solve(vector<int> &A, int B) {
    int xr=0;
    unordered_map<int,int>m;
    int count=0;
    m[xr]++;
    for(int i=0;i<A.size();i++)
    {
        xr=xr^A[i];
        int x=xr^B;
        count+=m[x];
        m[xr]++;
    }
    return count;
}
