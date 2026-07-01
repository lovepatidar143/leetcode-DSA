class Solution {
public:
    bool solve( vector<vector<int>> &arr , int dist ){
        if(arr[0][0] < dist) return false ; 
        int n = arr.size() ; 
        vector<vector<int>> visited(n , vector<int> ( n ,0)) ;
        visited[0][0] =1 ;

        queue < pair <int, int >> qu ; 
        qu.push({0,0}) ; 
        int dr[4] = {0 , 0, 1 , -1 } ; 
        int dc[4] = { 1 , -1 , 0 , 0} ; 
        while(!qu.empty()){
            auto [r, c] = qu.front();
            qu.pop() ; 
            if(r == n- 1 && c == n-1) return true ; 
            for(int i = 0 ; i< 4 ; i++){
                int nr = r + dr[i] ; 
                int nc = c + dc[i] ; 

                if(nr >=0 && nc >= 0 && nc < n && nr < n && arr[nr][nc] >= dist && !visited[nr][nc]){
                    visited[nr][nc] = 1 ; 
                    qu.push({nr , nc}) ; 
                }
            }

        }

        return false ; 
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n =grid.size() ;
        vector<vector<int>> arr(n ,vector<int> (n , -1)) ; 

        queue < pair <int , int >> qu ; 
        for(int i = 0 ; i<n ; i ++){
            for(int j = 0 ;j <n ; j++){ 
                if(grid[i][j] == 1){
                    qu.push({i,j}) ; 
                    arr[i][j]= 0 ;
                }
            }
        }

        int low = 0 , high = 0; 
        while(!qu.empty()){
            auto it = qu.front() ; 
            qu.pop() ; 
            int i = it.first ; 
            int j = it.second ; 
            int dr[4] = { 0 , 0 , -1 , 1} ; 
            int dc[4] = { -1 , 1 , 0 , 0} ; 
            for(int d = 0 ; d< 4 ; d++){
                int row = i + dr[d] ; 
                int col = j + dc[d] ; 
                if(row >= 0 && col >=0 && row < n && col < n && arr[row][col] == -1){
                    arr[row][col] = 1 + arr[i][j] ;
                    qu.push({row , col}) ; 
                    high = max(high , arr[row][col]) ; 
                }
            }
        }
        // bfs is done 
        while(low < high){
            // int mid = (low + high)/2 ;
            int mid = low + (high - low + 1)/2 ;
             
            // visited[0][0] =1 ; 
            bool check = solve(arr , mid) ; 

            if(check){
                low = mid  ; 
            }
            else {
                high = mid -1 ; 
            }
        }

        return low ; 
        
    }
};