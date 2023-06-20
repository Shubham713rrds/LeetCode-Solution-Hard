//KMP algorithm TC-->O(2*N) SC->O(2*N)
class Solution {
public:
    int findLps(string s){
        string temp=s;
        temp+='&';
        reverse(s.begin(),s.end());
        temp+=s;
        int n=temp.size();
        vector<int>lps(n, 0);
        for(int i=1;i<n;i++){
            int len=lps[i-1];
            while(len>0 && temp[i]!=temp[len]){
               len=lps[len-1];
            }
            if(temp[i]==temp[len]){
                len++;
            }
            lps[i]=len;
        }
        return (s.size()-lps[n-1]);
    }
    string shortestPalindrome(string s) {
        int n=s.size();
        int cnt=findLps(s);
        string temp=s.substr(n-cnt,cnt);
        reverse(temp.begin(), temp.end());
        s=temp+s;
        return s;
    }
};
