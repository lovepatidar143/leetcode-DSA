class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i< 9 ; i+= 3){
            for(int j = 0 ; j < 9 ; j += 3){
                vector<int> check(10 , 0) ; 
                for(int k= i ; k <= i+2 ; k ++){
                    for(int l = j ; l <= j+2 ; l++){
                        if(board[k][l]=='.') continue ;
                        if(check[board[k][l] - '1']) return false ;
                        else check[board[k][l]- '1'] =1 ;
                    }
                }
            }
        }
        int n = 9 ; 
        for(int i = 0 ; i<n ; i++ ){
            vector<int> check(n+1 , 0) ;
            for(int j = 0 ; j< n ; j++){
                if(board[i][j]=='.') continue ;
                if(check[board[i][j]- '1']) return false ;
                else check[board[i][j]- '1'] = 1 ;
            }
        }
        for(int j = 0 ; j < n ; j++){
            vector<int> check(n+1 , 0) ;
            for(int i = 0 ; i< n ; i++){
                if(board[i][j]=='.') continue ;
                if(check[board[i][j]- '1']) return false ;
                else check[board[i][j]- '1'] =1 ;
            }
        }


        return true ; 
    }
};