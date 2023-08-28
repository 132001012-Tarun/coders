// Online Stock Span

// this solution i have written but time complexity is very high just sufficient to satisfy the constraints
class StockSpanner {
public:
    vector<int>v;
    StockSpanner() {
    }
    
    int next(int price) {
        v.push_back(price);
        int count=1;
        for(int i=v.size()-2;i>=0;i--)
        {
            if(v[i]<=price)
            {
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};

// using stack


class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty()&&st.top().first<=price)
        {
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};
