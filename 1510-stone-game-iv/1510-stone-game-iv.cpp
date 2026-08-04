class Solution {
public:
    bool solve(int n , int turn , vector<int> &dp){
        if(n == 0) return false; 
        if(dp[n] != -1) return dp[n] ;
        bool solu = false ; 
        int x = floor(sqrt(n)) ; 
        for(int i = 1 ; i<= x ; i++){
            solu = solu || !solve(n - i*i , turn +1 , dp) ;
        }
        return dp[n] =  solu ;
    }
    bool winnerSquareGame(int n) {
        int cnt = 0 ;
        int num = n ;
        vector<int> dp(n+1 , -1) ; 
        return solve(n , cnt , dp)  ; 
        
    }
};