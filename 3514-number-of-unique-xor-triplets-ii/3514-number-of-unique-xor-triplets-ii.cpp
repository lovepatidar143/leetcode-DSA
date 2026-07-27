class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int ans = 0 ; 
        int n = nums.size() ; 
        vector<int> dp(2048 , 0) ; 
        vector<int> vp(2048 , 0) ; 
        // dp[0] =1 ; 
        for(int i = 0 ; i< n ; i++){
            for(int j = i ; j< n ; j++){
                dp[nums[i]^nums[j]] = 1 ; 
            }
        }

        for(int i = 0 ; i< 2048 ; i++){
            if(dp[i] == 0) continue ; 
            for(int j = 0 ; j < n ; j++){
                dp[i] = 0 ; 
                vp[i ^ nums[j]] = 1 ; 
            }
        }
        
        for(int i = 0 ; i< 2048; i++){
            if(vp[i]) ans++;
        }
        return ans ; 

    }
};