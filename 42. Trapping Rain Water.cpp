//Method-1  TC->O(N)  SC->O(N)
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int ans=0;
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=h[0];
        suffix[n-1]=h[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],h[i]);
            suffix[n-i-1]=max(suffix[n-i],h[n-i-1]);
        }
        for(int i=0;i<n;i++){
            ans+=(min(prefix[i],suffix[i])-h[i]);
        }
        return ans;
    }
};


//Method-2 TC-->O(N)  SC-->O(1)
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int ans=0;
        int rightMax=0,leftMax=0;
        int low=0,high=n-1;
        while(low<=high){
            if(h[low]<=h[high]){
                if(h[low]>=leftMax)leftMax=h[low];
                else{
                    ans+=(leftMax-h[low]);
                }
                low++;
            }
            else{
                if(h[high]>=rightMax)rightMax=h[high];
                else{
                    ans+=(rightMax-h[high]);
                }
                high--;
            }
        }
        return ans;
    }
};
