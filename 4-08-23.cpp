// Longest palindromic substring


//brute force     t.c o(n^3)   s.c o(1)
class Solution {
private: 
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
}; 

// optimzed solution    t.c o(n^2)     s.c   o(n^2)
class Solution {
public:
    bool solve(vector<vector<bool>>&dp,int i,int j,string &s)
    {
        if(i==j)
        {
            return dp[i][j]=true;   
        }
        if(j-1==i)
        {
            if(s[i]==s[j])
            {
                return dp[i][j]=true;
            }
            else
            {
                return dp[i][j]=false;
            }
        }
        else{
            if((s[i]==s[j])&&dp[i+1][j-1]==true)
            {
                return dp[i][j]=true;
            }
            else{
                return dp[i][j]=false;
            }
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start_index=0;
        int mx=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int g=0;g<n;g++)
        {                                 // loops are designed in such a way that it first checks the substring with len 1 then 2.....n
            for(int i=0,j=g;j<n;j++,i++)
            {
                solve(dp,i,j,s);
                if(dp[i][j]==true){
                    if(mx<j-i+1){
                    mx=j-i+1;
                    start_index=i;
                    }
                }
            }
        }
        return s.substr(start_index,mx);
    }
};
