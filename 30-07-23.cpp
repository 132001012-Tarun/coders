// N-QUEENS

//used backtracking concept
//we can do it in two ways
//1->inserting an element at each row of first column and recurcively calling for other column by considering the safe conditions and if safe is false then backtracking the step. in this case safe condition takes o(n)time complexity so overall time complexity is o(n^2);
//safe condition:
// for queen to be placed at a paricular row of a column we need to check the three conditions 1.weather queen is placed anywhere straight left of it.2.weather queen is at anywhere upperdiagonal of it 3.and similarly for lowerDiagonal.
//2->in this case safe condition has its different implementation we will store the leftRow of size n with 1 if queen is already stored in it. we will store the value of lowerDiagonal[row+col]=1 if queen is already in the diagonal whoose sum is row+col this lowerDioagonal will be of size (2*n-1), and we will store upperDiagonal[n-1+col-row]==1 if queen is already in the upper diagonal whoose size will be of 2*n-1.

//In this way we can reduce the time complexity.
class Solution {
public:
    void solve(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&leftRow,vector<int>&lowerBound,vector<int>&upperBound,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0&&lowerBound[row+col]==0&&upperBound[n-1+col-row]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;// for element present in the same row
                lowerBound[row+col]=1;   // for checking if an element is present in the diagonal element.   /.  this diagonal
                upperBound[n-1+col-row]=1;// for checking if an element is present in the diagonal element     \ this diagonal
                solve(col+1,ans,board,leftRow,lowerBound,upperBound,n);
                board[row][col]='.';
                leftRow[row]=0;
                lowerBound[row+col]=0;
                upperBound[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftRow(n,0),lowerBound(2*n-1,0),upperBound(2*n-1,0);
        solve(0,ans,board,leftRow,lowerBound,upperBound,n);
        return ans;
    }
};
