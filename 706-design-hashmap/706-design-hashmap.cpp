class MyHashMap {
public:
    vector<vector<pair<int,int>>>v;
     int ms=1000;
     /** Initialize your data structure here. */
    MyHashMap() {
        v.clear();
        v.resize(1000);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        if(v[key%ms].size()==0)
        {
            v[key%ms].push_back({key,value});
        }
        else
        {
            bool flag=1;
            for(int i=0;i<v[key%ms].size();i++)
            {
                if(v[key%ms][i].first==key)
                  {  
                    v[key%ms][i].second=value;
                    flag=0;
                  }
            }
            if(flag)
            {
                 v[key%ms].push_back({key,value});
            }
            
        }
        
    }
    
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        
        for(int i=0;i<v[key%ms].size();i++)
            {
                if(v[key%ms][i].first==key)
                  {  
                     return v[key%ms][i].second; 
                  }
            }
        return -1;
    }
    
       /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        
        for(int i=0;i<v[key%ms].size();i++)
            {
                if(v[key%ms][i].first==key)
                  {  
                    v[key%ms].erase(v[key%ms].begin()+i); 
                  }
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */