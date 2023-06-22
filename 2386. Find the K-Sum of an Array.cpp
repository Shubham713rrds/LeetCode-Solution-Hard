//TC-->O(NlogN + KlogK)
class Solution {
public:
    #define ll long long
    long long kSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a)<abs(b);
        });
        
        ll res=accumulate(nums.begin(), nums.end(), 0ll, [](ll temp, int ele){
               return temp+max(0, ele);
        });

        priority_queue<pair<ll, ll>>pq;
        pq.push({res-abs(nums[0]), 0});
        while(--k){
            auto [sum, i]=pq.top(); 
            pq.pop();
            if(i+1<nums.size()){
                pq.push({sum-abs(nums[i+1]), i+1});
                pq.push({sum+abs(nums[i])-abs(nums[i+1]), i+1});
            }
            res=sum;
        }
        return res;
    }
};
