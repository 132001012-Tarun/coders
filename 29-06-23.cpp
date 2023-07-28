// course schedule

//https://leetcode.com/problems/course-schedule/

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
        vis[i]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>adj[numCourses];
        for(auto pre:prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(isCycle(i,adj,vis))
            {
                return false;
            }
        }
        return true;
    }
};
