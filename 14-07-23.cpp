//Subsets II


// just imagine a recursive tree u will get an idea
// used the set data structure here so that it cannot take the duplicates
class Solution {
public:
    set<vector<int>> st;
    vector<int> num, v;
    void solve(int id) {
        st.insert(v);
        for(int i=id; i<num.size(); i++) {
            v.push_back(num[i]); 
            solve(i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        num = nums;
        solve(0);
        vector<vector<int>> ans;
        for(auto x: st) ans.push_back(x);
        return ans;
    }
};
