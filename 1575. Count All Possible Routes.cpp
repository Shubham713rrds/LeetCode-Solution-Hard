class Solution {
public:
    int mod=1e9+7;
    #define ll long long
    //TC-->O(fuel * n^2)
    int solve(vector<int>& locations, int finish, int idx, int fuel, vector<vector<int>>&dp){
        if(fuel<=0)return 0;
        
        if(dp[idx][fuel]!=-1)return dp[idx][fuel];
        ll cnt=0;
        for(int i=0;i<locations.size();i++){
            int fuelUsed=abs(locations[i]-locations[idx]);
            if(i!=idx && fuelUsed<=fuel){
                if(i==finish){
                    cnt=(cnt+1)%mod;
                }
                cnt=(cnt%mod+solve(locations, finish, i, fuel-fuelUsed, dp)%mod)%mod;
            }
        }
        return dp[idx][fuel]=cnt;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n=locations.size();
        vector<vector<int>>dp(n+1, vector<int>(fuel+1, 0));

        // int ans= solve(locations, finish, start, fuel, dp);  //{locations, finish, idx, fuel}

        if(start==finish){
            ans=(ans+1)%mod;
        }
        return ans;
    }
};
