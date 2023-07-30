//PRIMS ALGORITHM FOR MST

// first of all know the meaning of spanning tree (you have to select every vertex and vertex-1 edges such that it should not form a cycle) so you have to will
// get different such trees so you have to find the minimum cost tree.
// you can use brute force but that is complicated so for that you have 2 methods 
//1.prim's algorithm
//2. krushkals algo

// in case of prims algo the intution is that you have to select the minimum edge first and then the minimum edge which is connected to already existing mst in the next steps.

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(V,0);
        int sum=0;
        while(!pq.empty())
        {
            int u=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[u])continue;
            vis[u]=1;
            sum+=wt;
            for(auto node:adj[u])
            {
                int v=node[0];
                int wt=node[1];
                if(vis[v]==0)
                {
                    pq.push({wt,v});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
