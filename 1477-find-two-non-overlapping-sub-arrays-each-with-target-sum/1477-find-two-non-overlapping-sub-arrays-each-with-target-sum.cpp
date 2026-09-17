class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size() ; 
        unordered_map < int , int > hash ;
        hash[0] = -1 ;  
        int ans = n + 1 , minl = n ; 
        vector<int> dp(n , n+1) ; 
        int sum = 0 ;
        for(int i = 0 ; i< n ;  i++){
            sum += arr[i] ; 
            if(hash.find(sum - target) != hash.end()){
                int j = hash[sum -target] ;
                int l = i -  j;
                ans = min(ans , l + (j ==-1 ? n : dp[j]));
                minl = min(minl , l) ; 
            
                
            }
            dp[i] = minl ; 
            hash[sum] = i ; 
        }

        if(ans == n+1)  return -1 ; 
        return ans ; 
    }
};