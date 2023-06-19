class LFUCache {
public:
    int cap;
    int minFreq;
    int size;
    unordered_map<int, pair<int,int>>mp;  //key to {value, freq}
    unordered_map<int, list<int>::iterator>mpIter;  // key to  list iterator
    unordered_map<int, list<int>>freqm;    // freq to key list
    LFUCache(int capacity) {
        this->cap=capacity;
        minFreq=0;
        size=0;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
           int val=mp[key].first;
           freqm[mp[key].second].erase(mpIter[key]);
           mp[key].second+=1;
           freqm[mp[key].second].push_back(key);
           mpIter[key]=--freqm[mp[key].second].end();
           if(freqm[minFreq].size()==0){
               minFreq++;
           }
           return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0){
           return;
        }

        int storedValue=get(key);
        if(storedValue!=-1){
            mp[key].first=value;
            return;
        }

        if(cap==size){
           mp.erase(freqm[minFreq].front());
           mpIter.erase(freqm[minFreq].front()); 
           freqm[minFreq].pop_front();
           size--;
        }
        
        mp[key]={value, 1};
        freqm[1].push_back(key);
        mpIter[key]=--freqm[1].end();
        size++;
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
