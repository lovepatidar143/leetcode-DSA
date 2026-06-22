class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> dp(n ,1) ; 
        vector <int> hash(n) ;
        // vector <int> maxi(n)  ; 
        sort(nums.begin() , nums.end()) ; 
        for(int i = 0 ; i< n ; i++) {
            hash[i] = i ;
            // maxi[i] = nums[i] ; 
        }

        int ind = 0 , ans = 1 ; 

        for(int i = 0 ; i< n ; i++){
            for(int prev = 0 ; prev < i ; prev++){
                int n1 = nums[i] , n2 = nums[prev] ; 
                if(n1 % n2 == 0 || n2 % n1 == 0){
                    // maxi[i] = max(maxi[i] , maxi[prev]) ;
                    if(dp[i] < 1+ dp[prev]){
                        hash[i] = prev ;
                        dp[i] = 1 + dp[prev] ;
                    }
                }
            }
            if(dp[i] > ans){
                ans = dp[i] ;
                ind =  i ; 
            }
        }
        vector <int> sol ; 
        sol.push_back(nums[ind]);
        while(hash[ind] != ind ){
            ind = hash[ind] ; 
            sol.push_back(nums[ind]) ; 
        }
        reverse(sol.begin() , sol.end()) ; 
        return sol ; 
    }
};