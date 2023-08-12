// combination sum



class Solution {
public:
    void solve(int ind,vector<int>&candidates,int target,int sum,vector<int>&curr,vector<vector<int>>&res){
        if(target==sum)
        {
            res.push_back(curr);
            return;
        }
        if(target>sum||ind>=candidates.size())
        {
            return;
        }
        else{
            curr.push_back(candidates[ind]);
            solve(ind+1,candidates,target,sum+candidates[ind],curr,res);   // including the current candidate 
            curr.pop_back();// backtracking step
            solve(ind+1,candidates,target,sum,curr,res);   // excluding the current candidate
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>res;
        solve(0,candidates,target,0,curr,res);
        return res;
    }
};
