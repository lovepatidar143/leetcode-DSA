class Solution {
public:
    void dfs(int i,  int d,vector<int> &arr, vector<int> &dp ){
        if(i < 0) return ; 
        if(i >= arr.size()) return ;
        if(dp[i] != -1)  return ;
        int ind = i+1  , cur = arr[i]; 
        int n = arr.size() ;
        dp[i] =1 ; 
        while(ind <= i + d && ind < n && arr[ind] < cur  ){
            dfs(ind , d , arr , dp ) ; 
            dp[i] = max(dp[i] ,1 + dp[ind] ) ;
            ind++ ; 
        }
        ind = i -1; 
        while(ind >= i-d && ind >= 0 && arr[ind] < cur){
            dfs(ind , d , arr , dp) ; 
            dp[i] = max(dp[i] , 1 + dp[ind]) ; 
            ind--;
        }

    }
    int maxJumps(vector<int>& arr, int d) {
        int n =arr.size(); 
        vector<int> dp(n , -1) ; 
        for(int i = 0 ; i< n ; i++){
            // 
            dfs(i , d, arr , dp) ; 
        }

        return *max_element(dp.begin() , dp.end()) ; 
    }
};