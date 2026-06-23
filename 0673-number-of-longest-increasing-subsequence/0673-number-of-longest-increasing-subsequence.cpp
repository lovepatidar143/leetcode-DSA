class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size() ; 
        // the dp aaray to store the lenght of incrase subsequence
        vector <int> dp( n ,1 ) ; 
        // count array for to stor kittte he us len k 
        vector <int> cnt(n , 1 ) ; 
        int len =1 ; 
        int ans = 0 ; 
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0 ; prev < i ; prev++){
                // checking if this prev matches or not
                if(nums[i] > nums[prev]){
                    // if mathced maximise the len seen so far 
                    if(dp[i] < 1 + dp[prev]){
                        dp[i] = 1 + dp[prev] ;
                        cnt[i] = cnt[prev] ; 
                    }
                    else if(dp[i] == 1+ dp[prev]){
                        cnt[i] += cnt[prev] ; 
                    }

                }
                // if(dp[i] > len) {
                //     len = dp[i] ; 
                //     cnt[i] =1 ; 
                // }
                // else if(dp[i] == len) cnt[i] ++ ; 
            }

            // ans = max(ans , cnt[i]) ; 
            len = max(len , dp[i]) ; 
        }
        for(int i = 0 ; i< n ; i++) {
            if(dp[i] == len) ans += cnt[i] ; 
        }
        return ans ; 
    }
};