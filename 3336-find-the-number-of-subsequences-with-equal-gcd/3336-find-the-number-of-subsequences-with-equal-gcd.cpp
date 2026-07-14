class Solution {
public:
    const long long MOD = 1e9 + 7 ; 
    int solve(int i , vector<int> & nums , int gcd1 , int gcd2 , vector<vector<vector<int>>> & dp  ){
        //base case 
        if(i <0){
            if(gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2) return 1 ; 
            return 0  ; 
        }
        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2] ; 
        long long  cnt = 0 ; 
        long long  way1 , way2 , way3 ; 
        // skip 
        way3 = solve(i-1 , nums , gcd1 , gcd2 , dp) ; 

        // take in sequq ; 
        // take i in the first
        if(gcd1 == 0) way1 =   solve(i-1 , nums , nums[i] , gcd2 , dp ) ; 

        else  way1 = solve(i-1 , nums , gcd(gcd1 , nums[i]) , gcd2 , dp) ; 


        //take in sequ2 ; 
        if(gcd2 == 0) way2 =  solve(i-1 , nums , gcd1 , nums[i] , dp) ; 
        else way2 = solve(i-1 , nums , gcd1 , gcd(gcd2 , nums[i]) , dp) ; 
        
        cnt = (way1 + way2 + way3)%MOD ; 

        return dp[i][gcd1][gcd2] =  cnt   ; 
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size() ; 
        vector<vector<vector<int>>> dp(n , vector<vector<int>> (201 , vector<int> (201 , -1))) ; 

        return solve(n-1 , nums , 0 , 0 , dp ) ; 
    }
};