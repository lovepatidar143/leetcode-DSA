class Solution {
public:
    int solve(int i , int j , vector <int>&arr , vector<vector<int>> &dp){
        if(i>j) return 0 ; 
        // if(i == j) return arr[i]*arr[i-1]*arr[i+1]  ; 
        if(dp[i][j] != -1) return dp[i][j] ; 
        int coins = -1e9 ; 
        for(int  k= i ; k <= j; k++){
            int sikke = arr[k] * arr[i-1]*arr[j+1] + solve(i , k-1 , arr , dp) + solve(k+1 , j , arr , dp) ; 
            coins = max(coins , sikke) ;
        }
        return dp[i][j] = coins ; 
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size() ; 
        nums.push_back(1)  ; 
        nums.insert(nums.begin() , 1) ; 
        vector <vector <int>> dp(n+1 , vector<int>(n+1,-1) ) ;
        return solve(1 , n , nums , dp) ;
    }
};