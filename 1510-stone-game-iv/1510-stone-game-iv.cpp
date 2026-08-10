class Solution {
public:
    bool solve(int n , vector<int> &dp){
        if(n<=0) return false  ; 
        if(dp[n] != INT_MIN) return dp[n] ; 
        bool final = false ; 
        for(int i =1 ; i*i <= n ; i++){
            int remove = i*i ; 
            int turn = !solve(n - remove , dp) ; 
            final = final || turn ; 
        }
        return dp[n] = final ; 
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1 ,INT_MIN ) ; 
        // if(solve(n , dp) > 0) return true;÷ 
        // return false ; 
        return solve(n , dp) ; 
    }
};