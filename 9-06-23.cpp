// Course Schedule
class Solution {
public:
    bool isCycle(int i,vector<int>adj[],vector<int>&vis)
    {
        if(vis[i]==1)
        {
            return true;
        }
        if(vis[i]==0)
        {
            vis[i]=1;
            for(auto edge : adj[i])
            {
                if(isCycle(edge,adj,vis))
                {
                    return true;
                }
            }
        }
        vis[i]=2;// this is must as while calling the canFinish functions for loop it must not return  if(vis[i]==1)
       // {
        //    return true;
       // } true here always
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>adj[numCourses];   
        for(auto pre:prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);//  storing in a adjacency matrix
        }
        for(int i=0;i<numCourses;i++)
        {
            if(isCycle(i,adj,vis))
            {
                return false;       // if there is cycle then return false;
            }
        }
        return true;
    }
};
