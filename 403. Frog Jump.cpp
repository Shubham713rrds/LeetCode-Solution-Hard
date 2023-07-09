//TC-->O(3*n*logn) SC-->O(n*n)
class Solution {
public:
    #define ll long long
    bool solve(vector<int>&stones, int idx, int k, vector<vector<int>>&dp){
        if(idx==stones.size()-1)return true;
        
        if(dp[idx][k]!=-1)return dp[idx][k];
        bool ans=false;
        for(int t=-1;t<2;t++){
            int next_jump=k+t;
            if(next_jump<=0)continue;
            auto it=lower_bound(stones.begin(), stones.end(), stones[idx]+next_jump)-stones.begin();
            if(it!=stones.size() && stones[it]==stones[idx]+next_jump){
               ans=ans||solve(stones, it, next_jump, dp);
            }
        }
        return dp[idx][k]=ans;
    }
    bool canCross(vector<int>& stones) {
        if((stones[0]+1) != stones[1])return false;
        int n=stones.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        bool ans=solve(stones, 1, 1, dp);
        return ans;
    }
};
