//TOPOLOGICAL SORT 

//1. USING DFS   INTUITION IS LIKE IF U--->V THEN U MUST COMES BEFORE V     SO YOU MAKE SURE THAT YOU HAVE TO STORE THE LEAF NODE FIRST IN THE STACK 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int V,vector<int>adj[],stack<int>&st,vector<int>&visited,int i)
	{
	    if(visited[i]==1)
	    {
	        return;
	    }
	    visited[i]=1;
	    for(auto child:adj[i])
	    {
	        dfs(V,adj,st,visited,child);
	    }
	    st.push(i);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>st;
	    vector<int>visited(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	        {
	            dfs(V,adj,st,visited,i);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
// } Driver Code Ends



//2 . BFS USING KHAN'S ALGORITHM

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> in(V);
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            in[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(!in[i])q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int cur=q.front();
	        q.pop();
	        ans.push_back(cur);
	        for(int nb:adj[cur]){
	            in[nb]--;
	            if(in[nb]==0)q.push(nb);
	        }
	    }
	    return ans;
	}
};// USING INDEGREE IF THE INDEGREE IS 0 THEN STORE THAT IN QUEUE
