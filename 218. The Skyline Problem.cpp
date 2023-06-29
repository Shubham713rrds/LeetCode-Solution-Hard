//TC-->O(2*N*log(2*N))
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>>ans;
        vector<pair<int,int>>arr;
        for(int i=0;i<b.size();i++){
            arr.push_back({b[i][0], -b[i][2]});
            arr.push_back({b[i][1], b[i][2]});
        }
        sort(arr.begin(), arr.end());
        multiset<int>pq{0};
        int curHt=0;

        for(int i=0;i<arr.size();i++){
            int x=arr[i].first;
            int ht=arr[i].second;

            if(ht<0){
                pq.insert(-ht);
            }
            else{
                pq.erase(pq.find(ht));
            }
            
            auto pqTop=*pq.rbegin();
            if(curHt!=pqTop){
               ans.push_back({x, pqTop});
               curHt=pqTop;
            }
        }
        return ans;
    }
};
