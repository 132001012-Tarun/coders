// Largest Rectangle in Histogram


// intuition is u can find the next smaller and previous smaller element area between those can be find very easily this takes time complexity o(n) only


class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&h)
    {
        stack<int>st;
        int n=h.size();
        vector<int>ans(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1&&h[st.top()]>=h[i])
            {
                st.pop();
            }
                ans[i]=st.top();
                st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>&h)
    {
        stack<int>st;
        int n=h.size();
        vector<int>ans(n);
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1&&h[st.top()]>=h[i])
            {
                st.pop();
            }    
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int sz=heights.size();
        int l;
        int h;
        int area=0;
        int currArea;
        vector<int>next=nextSmallerElement(heights);
        vector<int>prev=prevSmallerElement(heights);
        for(int i=0;i<sz;i++)
        {
            h=heights[i];
            if(next[i]==-1)
            {
                next[i]=sz;
            }
            l=next[i]-prev[i]-1;
            currArea=l*h;
            area=max(area,currArea);
        }
        return area;
    }
};
