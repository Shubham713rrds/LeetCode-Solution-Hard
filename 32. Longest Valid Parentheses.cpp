//Method-1 TC-->O(N) SC-->O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0)return 0;
        stack<int>stIn;
        stIn.push(-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stIn.push(i);
            }
            else{
                stIn.pop();
                if(stIn.empty()){
                    stIn.push(i);
                }
                else{
                    ans=max(ans, i-stIn.top());
                }
            }
        }
        return ans;
    }
};


//Method -2  TC-->O(N)  SC--O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0, close=0;
        int n=s.length();
        int ans=0;
        //0-->n
        for(int i=0;i<n;i++){
            if(s[i]=='(')open++;
            else{
                close++;
            }
            if(open==close){
                ans=max(ans, 2*open);
            }
            if(close>open){
                close=open=0;
            }
        }

        //n-->0
        open=close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                ans=max(ans, 2*open);
            }
            if(close>open){
                close=open=0;
            }
        }
        return ans;
    }
};
