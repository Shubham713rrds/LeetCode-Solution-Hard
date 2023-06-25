//TC-->O(N*N) SC-->O(N*N)
class Solution {
public:
    int solve(vector<int>&cost, vector<int>&time, int i, int j, vector<vector<int>>&dp){
        if(j<=0)return 0;
        if(i==0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min(solve(cost, time, i-1, j, dp), cost[i-1]+solve(cost, time, i-1, j-time[i-1]-1, dp));
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int ans=solve(cost, time, n, n, dp);
        return ans;
    }
};
