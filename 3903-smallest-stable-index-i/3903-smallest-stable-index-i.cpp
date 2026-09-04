class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = -1 ; 
        int n = nums.size() ; 
        vector<int> arr(n , nums[n-1]) ; 
        int mini = nums[n-1] ; 
        for(int i = n-1 ; i>=0 ; i--){
            mini = min(mini , nums[i]) ; 
            arr[i] = mini ; 
        }
        int maxi = nums[0] ; 
        for(int i = 0 ; i< n ; i++){
            maxi = max(maxi , nums[i]) ; 
            if(maxi - arr[i] <= k ) return i ; 
        }
        return ans ; 
    }
};