//Min Stack

// have implemented everything in o(1) but except the getMin function 
// so for reducing that also u can do like u initialize a vector<pair<int,int>>v; and store value in first and min in second this way u can track min value untill this point

class MinStack {
public:
vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.size()==0)
        {
            v.push_back(val);
        }
        else{
            v.push_back(val);
        }
    }
    
    void pop() {
        v.erase(v.begin()+v.size()-1);
        return;
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        int mn=INT_MAX;
       for(int i=0;i<v.size();i++)
       {
           mn=min(mn,v[i]);
       }
       return mn;
    }
};
