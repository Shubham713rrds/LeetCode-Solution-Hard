class Solution {
public:
    //TC-->O(2^m * n)  //SC-->O(n+m)  n->no. of buildings m->no. of requests
    void solve(vector<vector<int>>& requests, int idx, int cnt, vector<int>&indegree, int n, int &ans){
        if(idx==requests.size()){
            for(int i=0;i<n;i++){
               if(indegree[i]!=0)return;
            }
            ans=max(ans, cnt);
            return;
        }
        indegree[requests[idx][0]]++;
        indegree[requests[idx][1]]--;
        solve(requests, idx+1, cnt+1, indegree, n, ans);
        indegree[requests[idx][0]]--;
        indegree[requests[idx][1]]++;
        solve(requests, idx+1, cnt, indegree, n, ans);
        return;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans=0;
        vector<int>indegree(n, 0);
        solve(requests, 0, 0, indegree, n, ans);
        return ans;
    }
};
