class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size() ; 
        long long sum = 0 ; 
        int mxi = INT_MIN ; 
        vector<int> pre(n) ; 
        for(int i = 0 ; i < n ; i++){
            mxi = max(mxi , nums[i]) ; 
            pre[i] = gcd(nums[i] , mxi) ; 
        }
        int low = 0 , high = n-1 ; 
        sort(pre.begin() , pre.end()) ; 
        while(low < high){
            int val = gcd(pre[low] , pre[high]);
            low ++ ; 
            high --;
            sum = sum + val ;
        }
        return sum ; 

    }
};