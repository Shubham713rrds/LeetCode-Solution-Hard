//TC-->(26*26*N) SC-->O(N)
class Solution {
public:
    int largestVariance(string s) {
        int len=0;
        int n=s.size();
        unordered_set<char>st(s.begin(), s.end());
        for(auto ch1: st){
            for(auto ch2:st){
                if(ch1==ch2)continue;
                int cnt=0;
                bool has_ch2=false;
                for(auto it:s){
                   if(it==ch1)cnt++;
                   if(it==ch2){
                      has_ch2=true;
                      cnt--;
                      if(cnt<0){
                          has_ch2=false;
                          cnt=0;
                      }
                   }
                   len=max(len, has_ch2?cnt:(s.size()!=cnt?cnt-1:0));
                }
            }
        }
        return len;
    }
};
