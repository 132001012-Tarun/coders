// minimum height trees


// intuition is easy like we have to find the mid point so that height is balanced either way 
// so to find the mid point we have to see to delete the node the with indegree again and 
// again and update the indegrees after deletion of leaf node
//you can see this image for more explanation
//https://assets.leetcode.com/users/images/8323cdbe-aad8-444b-9bc7-ad4667ed8a35_1599222280.0331495.png
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
        {
            return {};
        }
        if(n==1)
        {
            return {0};
        }
        vector<int>g[n];
        vector<int>res;
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int sz=q.size();
            res.clear();
            for(int i=0;i<sz;i++)
            {
                int c=q.front();
                q.pop();
                res.push_back(c);
                for(auto child:g[c])
                {
                    indegree[child]--;
                    if(indegree[child]==1)
                    {
                        q.push(child);
                    }
                }
            }
        }
        return res;
    }
};

//be carefull man i was very much confused with this problem while solving
