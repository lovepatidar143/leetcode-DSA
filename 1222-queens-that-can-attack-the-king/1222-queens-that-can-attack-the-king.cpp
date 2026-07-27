class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8, vector<int> (8,0)) ; 
        for(auto it : queens){
            board[it[0]][it[1]] =1 ; 
        }
        int n = 8 ; 
        vector<vector<int>> ans ; 
        int r = king[0] , c= king[1] ; 
        for(int i = r+1 ; i < 8 ; i++){
            if(board[i][c]){
                ans.push_back({i , c}) ; 
                break ; 
            }
        }
        for(int i = c + 1 ; i < 8 ; i++){
            if(board[r][i]){
                ans.push_back({r,i}) ; 
                break ;
            }
        }
        for(int i = r-1 ; i>=0 ; i--){
            if(board[i][c]){
                ans.push_back({i,c}) ; 
                break ; 
            }
            
        }
        for(int i = c-1 ; i >=0 ; i--){
            if(board[r][i]){
                ans.push_back({r,i}) ; 
                break ; 
            }
        }

        int i = r-1 , j = c+1 ; 
        while(i >= 0 && j < 8){
            if(board[i][j]){
                ans.push_back({i,j}) ; 
                break;
            }
            i--,j++;
        }

        i = r-1 , j = c -1 ; 
        while(i >=0 && j >=0){
            if(board[i][j]){
                ans.push_back({i,j}) ; 
                break ; 
            }
            i--, j--;
        }

        i = r+1 , j = c-1 ; 
        while(i < n && j >= 0){
            if(board[i][j]){
                ans.push_back({i,j}) ;
                break;
            }
            i++ , j--;
        }
        i = r+1 , j = c+1 ; 
        while(i < n && j < n ){
            if(board[i][j]){
                ans.push_back({i,j}) ; 
                break;
            }
            i++ , j++ ;
        }


        return ans; 
    }
};