// M-colouring Problem



// overalltime complexity will   o(m^n)   like in worst case you will try each and every possible colour to each and every node


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool is_safe(int vertex,bool graph[101][101],int n,vector<int>&colour,int color)
    {
        for(int i=0;i<n;i++)
        {
            if(i==vertex)
            {
                continue;
            }
            else{
                if(graph[i][vertex]==1)
                {
                    if(colour[i]==color)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool solve(int vertex,bool graph[101][101], int m, int n,vector<int>&colour)
    {
        if(vertex==n)
        {
            return true;
        }
        for(int i=1;i<=m;i++)
        {
            if(is_safe(vertex,graph,n,colour,i)){
                colour[vertex]=i;
                if(solve(vertex+1,graph,m,n,colour))
                {
                    return true;
                }
                else{
                    colour[vertex]=0;
                }
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>colour(n,0);
        return solve(0,graph,m,n,colour);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
