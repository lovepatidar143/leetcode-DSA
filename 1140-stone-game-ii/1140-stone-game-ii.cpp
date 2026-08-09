class Solution {
public:
    int solve(
        int i , 
        int m , 
        vector<int> &arr , 
        vector<int> &suff , 
        vector<vector<int>> &dp
    ){
        int n = arr.size();
        if(i >=n) return 0 ; 
        if(dp[i][m] != -1) return dp[i][m] ; 

        int remain = suff[i] ; 
        int ans = 0 ; 
        for(int x = 1 ; x <= 2*m ; x++){
            if(x + i > n ) break ; 

            int take = solve(i +x , max(m , x ) , arr , suff , dp) ; 
            int cur = remain - take ;
            ans = max(cur , ans) ; 
        }


        return dp[i][m] = ans ; 
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size() ;
        vector<int> suff(n+1 , 0) ; 
        for(int i = n-1 ; i >= 0 ; i--){
            suff[i] = suff[i+1] + piles[i] ; 
        }
        vector<vector<int>> dp(n , vector<int> (2*n+1 , -1)) ; 
        return solve(
            0 ,
            1 , 
            piles , 
            suff , 
            dp
        );
        

    }
};