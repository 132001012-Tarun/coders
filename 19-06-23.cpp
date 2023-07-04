//time based key-value store
// intuition is to find the value given key,timestamp just think in that direction

class TimeMap {
private:
    map<pair<int,string>,string>m;// timestamp,key,value
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[{timestamp,key}]=value;
    }
    
    string get(string key, int timestamp) {
        for(int i=timestamp;i>=0;i--)
        {
            if(m.find({i,key})!=m.end())
            {
                return m[{i,key}];
            }
        }
        return "";
    }
};
