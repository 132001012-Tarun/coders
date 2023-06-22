//COMBINATION SUM

class Solution {
public:
    void solve(vector<int>&candidates,int target,int i,vector<int>&curr,vector<vector<int>>&res){
        if(target==0)
        {
            res.push_back(curr);   // if we reached the target then push the curr into result
            return;
        }
        if(target<0||i>=candidates.size())
        {
            return;
        }
        for(int k=i;k<candidates.size();k++)
        {
            curr.push_back(candidates[k]);
            solve(candidates,target-candidates[k],k,curr,res);
            curr.pop_back();   // backtracking step
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>res;
        solve(candidates,target,0,curr,res);
        return res;
    }
};
