class Solution {
public:
    int solve(int i  , int j , int k , vector<int>&arr , vector<vector<int>> &dp){
        // if(i == j) return arr[i] ; 
        if(i >j) return 0 ;
        if(dp[i][j] != -1)  return dp[i][j]  ; 
        int maxi = arr[i] ;
        int ans = -1e9 ;  
        for(int p = i ; p <=j && p < i+k ; p++){
            maxi = max(maxi , arr[p]) ; 
            int val = maxi *(p-i+1) + solve(p+1 , j , k , arr , dp) ;
            ans = max(ans , val) ; 
        }

        return dp[i][j] = ans ; 
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ; 
        vector < vector <int>> dp( n ,vector<int> (n , -1)) ; 
        return solve(0 , n-1 , k , arr , dp)   ;
    }
};
