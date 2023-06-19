class Solution {
    //leetcode 84 problem solution
    int findArea(vector<int>&h){
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
public:
    // little bit modification in leetcode 84 
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>h(matrix[0].size(), 0);
        int maxArea=-1;
        int area;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    h[j]=0;
                }
                else{
                    h[j]++;
                }
            }
            area=findArea(h);
            maxArea=max(maxArea, area);            
        }
        return maxArea;
    }
};
