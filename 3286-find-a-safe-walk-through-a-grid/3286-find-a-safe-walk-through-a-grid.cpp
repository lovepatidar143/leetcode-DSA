class Solution {
public:
    bool solve(vector<vector<int>> & grid , int i , int j , int health , vector<vector<int>> & visit , vector<vector<vector<int>>> &dp){
        int m = grid.size() ; 
        int n = grid[0].size() ; 
        
        if(health <= 0) return false ; 
        if(i == m-1 && j == n-1 ) {
            return health > grid[i][j] ; 
        }
        if(dp[i][j][health] != -1) return dp[i][j][health] ; 

        int dr[4] = { 0 , 0 , -1 , 1} ; 
        int dc[4] = { -1 , 1 , 0 , 0} ; 
        visit[i][j] =1 ; 
        int ans = false ; 
        for(int d = 0 ; d< 4 ; d++){
            int nr = i+dr[d] ;
            int nc = j + dc[d] ; 
            if(nr >= 0 && nc >=0 && nr < m && nc < n && !visit[nr][nc]){
                if(solve(grid , nr , nc , health - grid[i][j] , visit ,dp )) return true ; 
            }
        }
        visit[i][j] = 0 ; 
        return dp[i][j][health] =  ans ; 
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() ; 
        int n = grid[0].size() ; 
        vector<vector<int>> visit(m , vector<int> (n , 0)) ; 
        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n ,vector<int> (health +1 , -1))) ; 
        return solve(grid ,0 , 0 , health , visit , dp ) ; 
    }
};