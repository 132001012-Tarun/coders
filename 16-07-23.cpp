// combination sum II


// in the combination problem i have done without using the for loop and in this problem i have done using the backtracking problem

class Solution {
public:
    void solve(vector<int>&candidates,int target,int i,vector<int>&curr,vector<vector<int>>&res)
    {
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        if(target<0||i>=candidates.size())return;
        for(int k=i;k<candidates.size();k++)
        {
            if(k>i && candidates[k]==candidates[k-1]) continue;    // this condition ensures that each candidate should be used once
            curr.push_back(candidates[k]);
            solve(candidates,target-candidates[k],k+1,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int>curr;
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,curr,res);
        return res;
    }
};
