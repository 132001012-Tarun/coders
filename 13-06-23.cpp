// ROTTEN ORANGES
class Solution {
public:
    vector<pair<int,int>>movements={{0,1},{1,0},{-1,0},{0,-1}};
    bool isValid(int x,int y,int n,int m)
    {
        if(x<0||x>=n||y<0||y>=m)
        {
            return false;
        }
        else{
            return true;
        }
    }
    int bfs(vector<vector<int>>&grid,int n,int m,int ans)
    {
        
        vector<vector<int>>lev(n,vector<int>(m,INT_MAX));    // it is to store the level(time taken for that orange to be rotten)
        queue<pair<int,int>>q;  
        for(int i=0;i<n;i++){
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==2)
                    {
                        q.push({i,j});    // store everything in a queue. please mind that queue(FIFO)
                         lev[i][j]=0;
                    }
                }
            }
        }
        while(!q.empty())
        {
            auto curr_v=q.front();
            q.pop();
            
                int x_c=curr_v.first;
                int y_c=curr_v.second;
            for(auto movement: movements){
                int child_x=x_c+movement.first;
                int child_y=y_c+movement.second;
            if(!isValid(child_x,child_y,n,m))continue;
            if(grid[child_x][child_y]==2||grid[child_x][child_y]==0)continue;
                q.push({child_x,child_y});// it will be pushed back
            lev[child_x][child_y]=lev[x_c][y_c]+1;  // its level will be stored. please note that once every element of level 1 is added then only level 2 will be added that's the purpose of using queue here.
                grid[child_x][child_y]=2;
                ans=max(ans,lev[child_x][child_y]);
            }
            
        }
            return ans;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        ans=bfs(grid,n,m,ans);   // bfs called it search in each and every levels used the queue
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;    // if there is still any rotten orange left then return -1
                }
            }
        }
       return ans; 
    }
};
