class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() ; 
        nums.push_back(1)  ; 
        nums.insert(nums.begin() , 1) ; 
        vector <int> arr = nums ; 
        vector <vector <int>> dp(n+2 , vector<int>(n+2,0) ) ;
        for(int i = n ; i >=1 ; i--){
            for(int j = i ; j <= n ; j++){
                int coin = -1e9 ;
                for(int k = i ; k <= j ; k++){
                    int sikke = arr[k] *arr[i-1]*arr[j+1] + dp[i][k-1] +dp[k+1][j];
                    coin = max(coin , sikke) ;
                }
                dp[i][j] = coin ; 
            }
        }
        return dp[1][n] ;  
    }
};