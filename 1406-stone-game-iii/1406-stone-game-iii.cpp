class Solution {
public:

    string stoneGameIII(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> dp(n+1 , 0) ; 

        dp[n-1] = nums[n-1] ; 
        for(int i = n-2 ; i>= 0 ; i--){
            int way1 = INT_MIN , way2 = INT_MIN , way3 = INT_MIN ; 
            way1 = nums[i] - dp[i+1] ; 
            int n = nums.size() ;
            if(i+1 < n) way2 = nums[i] + nums[i+1] - dp[i+2]; 
            if(i+2 < n) way3 = nums[i] + nums[i+1] + nums[i+2] - dp[i+3];
            dp[i] = max(
                {
                    way1 ,
                    way2 , 
                    way3 
                });
        }
        int ans = dp[0]; 

        if(ans > 0){
            return "Alice" ;
        }
        else if(ans == 0) return "Tie" ;
        return "Bob" ; 
    }
};