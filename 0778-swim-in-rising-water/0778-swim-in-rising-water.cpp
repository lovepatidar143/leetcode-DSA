class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int time = 0 ; 
        int n = grid.size() ; 
        priority_queue< pair<int ,pair <int , int >> , vector < pair<int ,pair<int , int>>> , greater<>> pq ; 
        vector<vector<int>> visited(n , vector<int> (n ,0)) ; 
        pq.push({grid[0][0] , {0,0}}) ; 
        time = grid[0][0] ; 
        int dr[4] = {0 , 0 , -1 ,1} ; 
        int dc[4] = { -1 , 1 , 0 , 0} ;
        visited[0][0] =1 ; 
        while(!pq.empty()){
            auto it = pq.top() ; 
            pq.pop() ; 
            time = max(time , it.first ) ; 
            int r = it.second.first , c = it.second.second ;
            if(r == n-1 && c == n-1) return time ; 
            for(int i = 0 ; i< 4 ; i++){
                int nr =r + dr[i] , nc = c + dc[i] ; 
                if(nr >=0 && nc >=0 && nr < n && nc < n && !visited[nr][nc]){
                    visited[nr][nc] =1 ; 
                    pq.push({grid[nr][nc] , { nr, nc}}) ; 
                }
            }
        }
        return -1 ; 
    }
};