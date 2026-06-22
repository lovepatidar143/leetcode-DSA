class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int range = prices[0] ; 
        for(auto it : prices) range = max(it , range) ;
        // vector <vector < int >> dp( n , vector <int> (2 , 0)) ; 
        // int ifbuy = 0 , ifDontbuy = prices[n-1] ; 
        vector <int> cur(2 , 0 ) , prev(2 , 0) ; 
        prev[0] = prices[n-1] , prev[1] = 0 ;
        // dp[n-1][0] = prices[n-1] ; 
        // dp[n-1][1] = 0 ; 
        for(int i = n-2 ; i >= 0 ; i--){
            for(int buy = 0 ; buy < 2 ; buy ++){
                if(buy){
                    cur[1] = max(-prices[i] + prev[0]  , prev[1]) ;
                    
                }
                else cur[0] = max(prices[i] + prev[1] , prev[0]) ;
                prev = cur ; 
            }
        }
        return cur[1] ; 
    }
};