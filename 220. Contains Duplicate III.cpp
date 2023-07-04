//TC-->O(N*log(k)) SC-->O(2*k)
//N-->size of nums vector , k-->indexDiff
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        int j=0;
        multiset<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.size()>=indexDiff+1){
                auto it=st.find({nums[j], j});
                st.erase(it);
                j++;
            }
            st.insert({nums[i], i});
            auto it=st.find({nums[i], i});
            if(it==st.begin()){
               auto R=next(it);
               if(R!=st.end()){
                  if(R->first - it->first<=valueDiff)return true;
               }
            }
            else{
               auto L=prev(it);
               auto R=next(it);
               if(it->first - L->first<=valueDiff){
                   return true;
               }
               if(R!=st.end()){
                  if(R->first - it->first<=valueDiff)return true;
               }
            }
        }
        return false;
    }
};
