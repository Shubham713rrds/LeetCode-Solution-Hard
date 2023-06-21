//Greedy + sorting  TC-->O(N* logN)
class Solution {
public:
    #define ll long long
    ll solve(vector<int>&nums, vector<int>&cost, ll median){
        ll ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(1ll*nums[i]-median)*(1ll*cost[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll total=0;
        ll sum=0;
        ll n=nums.size();

        vector<pair<ll,ll>>v;
        for(int i=0;i<n;i++)v.push_back({nums[i], cost[i]});

        sort(v.begin(), v.end());

        for(int i=0;i<n;i++) sum+=v[i].second;

        ll median;
        int i=0;
        while(total<(sum+1)/2 && i<n){
            total+= 1ll*v[i].second;
            median=v[i].first;
            i++;
        }
        return solve(nums, cost, median);
    }
};


// Binary search Method || TC-->O(N *log(1e6))
class Solution {
public:
    #define ll long long
    ll chkFunc(vector<int>&nums, vector<int>&cost, ll mid){
        int n=nums.size();
        ll tempAns=0;
        for(int i=0;i<n;i++){
            tempAns+= 1ll *abs(mid-nums[i]) * cost[i];
        }
        return tempAns;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();        
        ll ans=LLONG_MAX;
        ll low=0, high=1000000, mid;
        while(low<high){
            mid=low+(high-low)/2;
            ll y1=chkFunc(nums, cost, mid), y2=chkFunc(nums, cost, mid+1);
            ans=min(y1, y2);
            if(y1<y2){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
