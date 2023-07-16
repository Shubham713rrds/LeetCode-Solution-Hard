//Memoization 
class Solution {
public:
    // TC-->O(m * 2^skills)  Sc-->O(m * 2^skills)
    int solve(vector<int>&people, int &req_mask, int idx, int mask, vector<vector<int>>&dp, vector<vector<bool>>&choice){
        if(mask==req_mask){
            return 0;
        }
        if(idx==people.size())return 1e4;
        if(dp[mask][idx]!=-1)return dp[mask][idx];

        int chk1=solve(people, req_mask, idx+1, mask|people[idx], dp, choice)+1;
        int chk2=solve(people, req_mask, idx+1, mask, dp, choice);

        if(chk1<chk2){
            choice[mask][idx]=1;
        }
        return dp[mask][idx]=min(chk1, chk2);
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people_skills) {
        int n=req_skills.size();
        int m=people_skills.size();
        unordered_map<string, int>skills;
        for(int i=0;i<n;i++){
            skills[req_skills[i]]=i;
        }

        vector<int>people;
        for(auto it: people_skills){
            int h=0;
            for(auto i: it){
               h|=(1<<skills[i]);
            }
            people.push_back(h);
        }

        int req_mask=(1<<n)-1;
        vector<vector<int>>dp(1<<16, vector<int>(64, -1));
        vector<vector<bool>>choice(1<<16, vector<bool>(64, 0));
        solve(people, req_mask, 0, 0, dp, choice);  // {people, idx, mask, dp, choice}
        
        vector<int>ans;
        for(int i=0, mask=0; i<m ; i++){
           if(choice[mask][i]==1){
               ans.push_back(i);
               mask|=people[i];
           }

           if(mask==req_mask)break;
        }
        return ans;
    }
};


//bottom up approach
class Solution {
public:
    //TC-->O(people * 2^skills) SC-->O(2^skills)
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        unordered_map<int, vector<int>>dp;
        dp.reserve(1<<n);
        dp[0]={};
        
        unordered_map<string, int>skills;
        for(int i=0;i<n;i++){
            skills[req_skills[i]]=i;
        }

        for(int i=0;i<people.size();i++){
            int cur_skill=0;
            for(auto it: people[i]){
                cur_skill|=(1<<skills[it]);
            }

            for(auto it=dp.begin(); it!=dp.end(); it++){
                int comb= it->first | cur_skill;
                if(dp.find(comb)==dp.end() || dp[comb].size()> 1+dp[it->first].size()){
                    dp[comb]=it->second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
