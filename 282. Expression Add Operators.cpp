class Solution {
public:
   #define ll long long
   void solve(string &num, int &target, ll idx, string s, vector<string>&ans, ll prev, ll cur){
       if(num.size()==idx){
          if(cur==target){
              ans.push_back(s);
              return;
          }
          return;
       }
       if(num[idx]=='0'){
            if(idx==0){
                solve(num, target, idx+1, s+"0", ans, 0, cur);
            }
            else{
                solve(num, target, idx+1, s+"+"+"0", ans, 0, cur);
                solve(num, target, idx+1, s+"-"+"0", ans, 0, cur);
                solve(num, target, idx+1, s+"*"+"0", ans, prev*0, (cur-prev)+(prev*0));
            }
       }
       else{
            for(ll i=idx+1;i<=num.size();i++){
                string temp=num.substr(idx, i-idx);
                ll val=stoll(temp);
                if(idx==0){
                  solve(num, target, i, s+temp, ans, val, val);
                }
                else{
                  solve(num, target, i, s+"+"+temp, ans, val, cur+val);
                  solve(num, target, i, s+"-"+temp, ans, -val, cur-val);
                  solve(num, target, i, s+"*"+temp, ans, prev*val, (cur-prev)+prev*val);
                }
            }
       }
       return;
       
   }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        solve(num, target, 0, "", ans, -1, 0);
        return ans;
    }
};
