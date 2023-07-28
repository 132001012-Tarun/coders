// course schedule

//https://leetcode.com/problems/course-schedule/


// using dfs

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


//Perform topological sort using BFS (Kahn's algorithm)

// logic is somewhat similar to what you have done on 27-06-23 on fiding the MHT (removing all the leaf nodes) 
// in this case you count what you are removing and if your are unable to remove all then cycle must have exist
//please see that this is undirected and In case of MHT is directed

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> indeg;
    vector<bool> visited;
    
    void build_adj(vector<vector<int>>& prerequisites) {
        for (vector<int>& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        indeg.resize(numCourses);
        visited.resize(numCourses, 0);
        
        build_adj(prerequisites);

        // Perform topological sort using BFS (Kahn's algorithm)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) 
                q.push(i);
        }
        
        int count = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            count++;
            for (int j : adj[i]) {
                if (--indeg[j] == 0) 
                    q.push(j);
            }
        }

        return count == numCourses; 
    }
};
