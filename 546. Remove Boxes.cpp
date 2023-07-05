class Solution {
public:
    int solve(vector<int>&boxes, int l, int r, int k, int dp[101][101][101]){
        if(l>r)return 0;
        if(dp[l][r][k]!=-1)return dp[l][r][k];
        int a=l, b=r, c=k;

        while(l<r && boxes[r]==boxes[r-1]){
            r--;
            k++;
        }
        int ans=solve(boxes, l, r-1, 0, dp)+(k+1)*(k+1);
        for(int i=l;i<r;i++){
            if(boxes[i]==boxes[r]){
                ans=max(ans, solve(boxes, l, i, k+1, dp)+solve(boxes, i+1, r-1, 0, dp));
            }
        }
        return dp[a][b][c]=ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        int dp[101][101][101];
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, n-1, 0, dp); //{boxes, l, r, k, dp};
    }
};
