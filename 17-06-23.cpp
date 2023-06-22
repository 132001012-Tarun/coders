//Merge intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());    // sort based on the starting time
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(end>=intervals[i][0]).  // if there is overlap
            {
                end=max(intervals[i][1],end);   // change the end time
            }
            else{// if there is no overlap 
                    ans.push_back({start,end});    
                    start=intervals[i][0];
                    end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
