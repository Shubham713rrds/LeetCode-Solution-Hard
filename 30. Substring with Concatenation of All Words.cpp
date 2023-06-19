class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        bool flag=true;
        int len=words[0].size();
        int totalLen=len*words.size();
        for(int i=0;i<s.size()-totalLen+1;i++){
            unordered_map<string,int>mp;
            flag=true;
            for(auto it: words){
                mp[it]++;
            }
            for(int j=i;j<i+totalLen;j+=len){
                string temp=s.substr(j, len);
                if(mp.find(temp)!=mp.end()){
                    if(--mp[temp]==-1){
                        flag=false;
                        break;
                    }
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag)ans.push_back(i);
        }
        return ans;
    }
};
