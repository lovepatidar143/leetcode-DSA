class Solution {
public:
    int solve(int start , int end , vector<int> &pref , vector<vector<int>> &dp ){

        if(end <= start) return 0 ; 
        if(dp[start][end] != -1) return dp[start][end] ; 

        int sol = 0 ; 
        for(int i = start ; i < end;  i++){
            int left = pref[i] ; 
            if(start != 0) left = pref[i] - pref[start -1] ; 
            int right = pref[end] - pref[i] ; 
            int ans ; 
            if(left > right){
                ans =  right + solve(i +1 , end , pref , dp ) ; 
            }
            else if(right > left){
                ans = left + solve(start , i , pref, dp ) ; 
            }
            else {
                ans = max(
                    right + solve(i +1 , end , pref , dp ),
                    left + solve(start , i , pref , dp ) 
                );
            }
            sol = max(sol , ans)  ; 
        }
        

        return dp[start][end] = sol ; 
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n   = stoneValue.size() ; 
        vector<int> pref(n , 0) ; 
        pref[0] = stoneValue[0] ; 
        for(int i =1 ; i< n ; i++){
            pref[i] = pref[i-1] + stoneValue[i] ; 
        }
        vector<vector<int>> dp(n , vector<int> (n , -1)) ; 
        return solve(0 , n-1 , pref , dp) ;
    }
};