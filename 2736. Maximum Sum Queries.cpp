class Solution {
    
    void update(map<int,int>&mp, int y, int sum){
        auto it=mp.lower_bound(y);
        if(it!=mp.end() && it->second >= sum){
            return;
        }
        
        if(it!=mp.begin()){
            --it;
            while(it->second <= sum){
                if(it==mp.begin()){
                    mp.erase(it);
                    break;
                }
                else{
                    mp.erase(it);
                    --it;
                }
            }
        }
        mp.insert({y, sum});
        return;
    }
    
    int query(map<int,int>&mp, int key){
        auto it=mp.lower_bound(key);
        return it==mp.end()?(-1):it->second;
    }
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();
        int m=queries.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={nums1[i], nums2[i]};
        }
        sort(v.begin(), v.end());
        vector<int>ind(m);
        for(int i=0;i<m;i++){
            ind[i]=i;
        }
        
        sort(ind.begin(), ind.end(), [&](const int x, const int y){
            return queries[x][0]>queries[y][0];
        });
        
        vector<int>res(m);
        map<int,int>mp;
        
        for(int q=0, j=n-1; q<m; q++){
            for(;j>=0 && v[j].first>=queries[ind[q]][0]; --j){
                update(mp, v[j].second, v[j].first+v[j].second);
            }
            res[ind[q]]=query(mp, queries[ind[q]][1]);
        }
        return res;
    }
};
