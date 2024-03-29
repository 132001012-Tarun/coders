// DIJKSTRA ALGORITHM  

// FINDING THE SHORTEST PATH FROM A SOURCE TO THE DIFFERENT NODES 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> weight(V,INT_MAX);    
        weight[S]=0;    //INITIALLY DISTANCE FROM THE SOURCE TO THE ALL IS INFINITY 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;   // MIN HEAP PLEASE SEE THE USE CAREFULLY
        pq.push({0,S});
        while(!pq.empty())
        {
            int currwgt=pq.top().first;   // minimum weight to reach the currnode 
            int currnode=pq.top().second;
            pq.pop();
            for(auto neighbour:adj[currnode])
            {
                if(weight[neighbour[0]]>currwgt+neighbour[1])   // updating the weight 
                {
                    weight[neighbour[0]]=currwgt+neighbour[1];
                    pq.push({weight[neighbour[0]],neighbour[0]});
                }
            }
        }
        return weight;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
