// Rat in a maze (geeksforgeeks)


// User function template for C++
//overall time complexity o(3^(n^2))

class Solution{
    public:
    void solve(int row,int col,vector<vector<int>>&m,vector<string>&ans,string moves,int n,vector<vector<int>>&vis)
    {
        if(row==n-1&&col==n-1)
        {
            ans.push_back(moves);
            return;
        }
        if(row+1<n&&!vis[row+1][col]&&m[row+1][col]==1)
        {
            vis[row][col]=1;
            solve(row+1,col,m,ans,moves+'D',n,vis);
            vis[row][col]=0;
        }
        if(col-1>=0&&!vis[row][col-1]&&m[row][col-1]==1)
        {
            vis[row][col]=1;
            solve(row,col-1,m,ans,moves+'L',n,vis);
            vis[row][col]=0;
        }
        if(col+1<n&&!vis[row][col+1]&&m[row][col+1]==1)
        {
            vis[row][col]=1;
            solve(row,col+1,m,ans,moves+'R',n,vis);
            vis[row][col]=0;
        }
        if(row-1>=0&&!vis[row-1][col]&&m[row-1][col]==1)
        {
            vis[row][col]=1;
            solve(row-1,col,m,ans,moves+'U',n,vis);
            vis[row][col]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,(vector<int>(n,0)));
        if(m[0][0]==0)
        {
            ans.push_back("-1");
            return ans;
        }
        solve(0,0,m,ans,"",n,vis);
        return ans;
    }
};

    
