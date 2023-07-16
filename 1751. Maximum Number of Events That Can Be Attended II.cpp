//TC-->(events.size() * k *log(events.size()))  SC-->O(events.size() *k)
class Solution {
    #define ll long long
public:
    static bool comp(vector<int>&ele1, vector<int>&ele2){
        return ele1[0]<ele2[0];
    }

    ll solve(vector<vector<int>>&events, int k, int idx, vector<vector<ll>>&dp){
        if(idx>=events.size() || k<=0){
            return 0;
        }
        if(dp[idx][k]!=-1)return dp[idx][k];

        vector<int>temp={events[idx][1], INT_MAX, INT_MAX};
        auto it=upper_bound(events.begin(), events.end(), temp)-events.begin();
        ll take=events[idx][2]+solve(events, k-1, it, dp);
        ll notTake=solve(events, k, idx+1, dp);
       
        // cout<<it<<" "<<k<<" "<<idx<<endl;
        return dp[idx][k]= max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comp);
        vector<vector<ll>>dp(events.size()+1, vector<ll>(k+1, -1));
        ll ans=solve(events, k, 0, dp);
        return ans;
    }
};
