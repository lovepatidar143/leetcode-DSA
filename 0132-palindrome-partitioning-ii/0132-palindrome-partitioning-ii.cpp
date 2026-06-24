class Solution {
public:

    int minCut(string s) {
        int n = s.size() ; 
        vector<int> dp( n+1 , 0); 

        // int i = 0 , j = n-1 ;
        vector<vector<int>> check( n , vector<int> (n , 0)) ;
        // for(int i = 0 ; i < n ; i++) check[i][i] =1 ; 
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = i ; j < n ; j++){
                if(s[i] == s[j]){
                    if(j-i <= 2) check[i][j] = true ; 
                    else check[i][j] = check[i+1][j-1] ; 
                }
            }
        }




        for(int i = n-1 ; i >= 0 ; i--){
            int nini = 1e9 ; 
            for(int k = i ; k < n ; k++){
                if(check[i][k]){
                    int mini = 1 + dp[k+1] ; 
                    nini = min(mini, nini) ; 
                }
            }
            dp[i] = nini ; 
        }

    

        return -1 + dp[0] ; 
    }
};