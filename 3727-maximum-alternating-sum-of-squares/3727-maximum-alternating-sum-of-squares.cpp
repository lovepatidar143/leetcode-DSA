class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ; 
        for(int i = 0 ; i< n ;i ++){
            nums[i] = abs(nums[i] -0 ) ; 
        }
        long long ans = 0 ; 
        sort(nums.begin() , nums.end()) ; 
        for(int i  = 0 ; i< n/2 ; i++){
            ans = ans - 1LL*nums[i]*nums[i] ; 
            
        }
        for(int i = n/2 ; i < n ; i++){
            ans = ans + 1LL*nums[i]*nums[i] ; 
        }
        return ans ; 
    }
};