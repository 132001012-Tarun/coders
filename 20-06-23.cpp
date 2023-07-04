//SPIRAL MATRIX

// JUST THINK OF LIKE TRAVERSING DEPTH WISE MAKE ONE VISITED ARRAY TRAVERSE RIGHT FIRST THEN DOWN THEN LEFT THEN UP WHILE UP TAKE CARE OF SOME CONDITION (I<=J)



#define VISITED     -1000
    class Solution {
public:
    vector<int>ans;
    void dfs(int i,int j,vector<vector<int>>&matrix,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n)
        {
            return;
        }
        if(matrix[i][j]==VISITED)
        {
            return;
        }
        ans.push_back(matrix[i][j]);
        matrix[i][j]=VISITED;
        if(i<=j+1)
        {
            dfs(i,j+1,matrix,m,n);
        }
        dfs(i+1,j,matrix,m,n);
        dfs(i,j-1,matrix,m,n);
        dfs(i-1,j,matrix,m,n); 
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        dfs(0,0,matrix,m,n);
        return ans;
    }
};
