class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid[0].size() ; 
        int n = grid.size() ; 
        k = k % (m*n) ;
        vector<int> flat; 
        for(int i = 0 ; i< n ; i++){
            for(auto it : grid[i]) flat.push_back(it) ; 
        }
        reverse(flat.begin() , flat.end()) ; 
        reverse(flat.begin() +k , flat.end());
        reverse(flat.begin() , flat.begin() + k) ; 
        int x = 0 ; 
        for(int i = 0 ; i < n ;i++ ){
            for(int j = 0 ; j< m ; ++j){
                grid[i][j] = flat[x] ; 
                x++;
            }
        }

        return grid ; 

    }
};