class Solution {
public:
    int solve(int i , int j , vector <int> &arr , vector < vector <int>> &dp){
        if(j-i <= 1 ) return 0 ; 

        if(dp[i][j] != -1) return dp[i][j] ; 
        int price = 1e9 ; 
        for(int k = i+1; k < j ; k++){
            int cost = arr[j] - arr[i] + solve(i , k , arr , dp ) + solve(k , j , arr , dp) ;
            price = min(price , cost) ; 
        }
        return dp[i][j] = price ; 
    }
    int minCost(int n, vector<int>& cuts) {
        vector <int> arr = cuts ; 
        arr.insert(arr.begin() , 0) ;
        arr.push_back(n) ; 
        int m = arr.size() ; 
        sort(arr.begin() , arr.end()) ; 
        vector < vector <int>> dp(m , vector <int> (m , -1)) ; 
        return solve(0 , m- 1 , arr , dp ) ; 
    }
};