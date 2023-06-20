// K closest points to origin
  // have used priority queue to sort it according to the greatest distance order
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++)
        {
            int dist=pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({dist,{points[i][0],points[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            auto it=pq.top().second;
            pq.pop();
            vector<int>temp;
            temp.push_back(it.first);
            temp.push_back(it.second);
            ans.push_back(temp);
        }
        return ans;
    }
};
