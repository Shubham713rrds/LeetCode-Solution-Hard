class Solution {
public:
    // bool isPalindrome(int i, int j, string &s){
    //     if(i==j || i>j)return true;
    //     while(i<j){
    //         if(s[i]!=s[j])return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
     
    //TC-->O(N*N)  SC-->O(N*N + N) 
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1, -1);
        //use of palindrome computation without using palindromic function again & again
        vector<vector<bool>>palin(n+1, vector<bool>(n+1, false));
        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int k=i;k<n;k++){
                if(s[i]==s[k] && (k-i<2 || palin[i+1][k-1])){
                    palin[i][k]=true;
                    int cost=1+dp[k+1];
                    minCost=min(minCost, cost);
                }
            }
            dp[i]=minCost;
        }
        return dp[0]-1;
    }
};
