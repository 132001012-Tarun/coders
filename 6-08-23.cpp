// LRU CACHE

class LRUCache {
public:
    unordered_map<int,int>m;
    int sz;
    vector<int>v;
    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
        {
            return -1;
        }
        else{
             auto it = find(v.begin(), v.end(), key);
             v.erase(it);
             v.push_back(key);
             return m[key];
        }
    }
    
    void put(int key, int value) {
        if(m.size()>=sz)
        {
            if(m.find(key)==m.end())
            {
                m.erase(v[0]);
                v.erase(v.begin());
                m[key]=value;
                v.push_back(value);
            }
            else{
                m.erase(key);
                auto it=find(v.begin(),v.end(),key);
                v.erase(it);
                v.push_back(key);
                m[key]=value;
            }
        }
        else{
            if(m.find(key)==m.end())
            {
                v.push_back(key);
                m[key]=value;
            }
            else{
                m.erase(key);
                auto it=find(v.begin(),v.end(),key);
                v.erase(it);
                v.push_back(key);
                m[key]=value;
            }
        }
    
    }
};

