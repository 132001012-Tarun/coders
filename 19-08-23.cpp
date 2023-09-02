// Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool flag=false;
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            while(!st.empty()&&st.top()>0&&asteroids[i]<0)
            {
                if(st.top()>(-1*asteroids[i]))
                {
                    flag=true;
                    break;
                }
                else if(st.top()==(-1*asteroids[i]))
                {
                    st.pop();
                    flag=true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(flag==false){
                st.push(asteroids[i]);
            }
            flag=false;
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
