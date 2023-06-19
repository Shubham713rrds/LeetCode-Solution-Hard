class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        int n=h.size();
        vector<int>leftsmall(n,-1);
        vector<int>rightsmall(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>h[i]){
               rightsmall[st.top()]=i;
               st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>h[i]){
               leftsmall[st.top()]=i;
               st.pop();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            if(rightsmall[i]==-1 && leftsmall[i]==-1){
                ans=max(ans,h[i]*(n));
            }
            else if(rightsmall[i]==-1){
                ans=max(ans, h[i]*(n-leftsmall[i]-1));
            }
            else if(leftsmall[i]==-1){
                ans=max(ans, h[i]*(rightsmall[i]));
            }
            else{
                ans=max(ans, h[i]*(rightsmall[i]-leftsmall[i]-1));
            }
        }
        return ans;
    }
};
