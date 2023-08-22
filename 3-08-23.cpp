// Maximum sum combinations


// intuition is that maximum elements should be added in the priority queue in the C loop

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    vector<int>ans;
    
    set<vector<int>>s;
    priority_queue<vector<int>>pq;
    pq.push({A[0]+B[0],0,0});
    s.insert({0,0});
    int cnt=0;
    while(cnt<C)
    {
        auto top=pq.top();
        ans.push_back(top[0]);
        pq.pop();
        int i=top[1];
        int j=top[2];
        
        if(s.find({i+1,j})==s.end()&&((i+1)<A.size()))
        {
            pq.push({A[i+1]+B[j],i+1,j});
            s.insert({i+1,j});
        }
        if(s.find({i,j+1})==s.end()&&((j+1)<B.size()))
        {
            pq.push({A[i]+B[j+1],i,j+1});
            s.insert({i,j+1});
        }
        cnt++;
    }
    return ans;
}
