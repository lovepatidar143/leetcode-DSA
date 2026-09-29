class Solution {
public:
    int n , m  ; 
    vector<vector<vector<int>>> dp ; 
    bool solve(vector<vector<char>> & grid , int i , int j , int cnt){
 
        if(cnt <0 ) return false ;
        if(i == n-1 && j == m-1) return cnt == 1 && grid[i][j] == ')' ; 
        if(i >= n || j >= m) return false ; 
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        int newCnt ; 
        if(grid[i][j] == '(') newCnt = cnt +1 ; 
        else newCnt = cnt -1 ; 
        return dp[i][j][cnt] = solve(grid , i +1 , j , newCnt) || solve(grid , i , j+1 , newCnt) ; 

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n , vector<vector<int>> (m , vector<int> (n+m +1 , -1))) ; 
        return solve(grid , 0 , 0 , 0) ; 
        

    }
};