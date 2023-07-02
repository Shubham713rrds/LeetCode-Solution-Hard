//TC-->O(N*N*log(N)  SC-->O(N)
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<pair<int,int>>st;
            int cnt=0;
            for(int j=i;j<n;j++){
                st.insert({nums[j], j});
                auto it=st.find({nums[j], j});
                if(it!=st.begin()){
                    auto L=prev(it);
                    auto R=next(it);
                    if(R!=st.end()){
                        cnt-=abs(R->first-L->first)>1;
                        cnt+=abs(R->first-it->first)>1;
                    }
                    cnt+=abs(L->first - it->first)>1;
                }
                else{
                    auto R=next(it);
                    if(R!=st.end()){
                        cnt+=abs(R->first - it->first)>1;
                    }
                }
                ans+=cnt;
            }
        }
        return ans;
    }
};
