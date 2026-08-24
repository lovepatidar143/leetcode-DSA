class Solution {
public:
    int solve(int i , vector<int> &pre, vector<int> &dp){
        int n = pre.size() ; 
        //base condition 
        if(i == n-1) return dp[i] =  pre[i] ; 
        if(dp[i] != INT_MIN) return dp[i] ; 
        int take , nottake ; 
        take = pre[i]  - solve(i +1 , pre , dp);  
        nottake = solve(i +1 , pre , dp) ; 
        return dp[i] = max(take , nottake) ; 
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size() ; 
        vector<int> pre(n , 0) ; 
        pre[0] = stones[0] ; 
        for(int i = 1 ; i< n ; i++) pre[i] = pre[i-1] + stones[i] ; 
        vector<int> dp( n , INT_MIN ) ;  
        return solve(1 , pre, dp) ; 
    }
}; 