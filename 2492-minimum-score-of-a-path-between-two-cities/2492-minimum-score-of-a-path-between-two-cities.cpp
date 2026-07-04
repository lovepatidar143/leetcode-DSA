class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair <int, int >>> adj (n+1) ; 
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]}) ;
            adj[it[1]].push_back({it[0] , it[2]}) ;
        }
        // now find who who is connected to the 1 and n 
        vector<int> visited(n+1 , 0) ; 
        queue < int > q ; 
        q.push(1) ; 
        visited[1] = 1 ; 
        int ans = INT_MAX ; 
        while(!q.empty()){
            int node = q.front() ; 
            q.pop();
            for(auto it : adj[node]){
                int newNode = it.first ; 
                ans = min(ans , it.second) ; 
                if(!visited[newNode]){

                    visited[newNode] =1 ; 
                    q.push(newNode) ; 
                }
            }
        }
        return ans ; 
    }
};