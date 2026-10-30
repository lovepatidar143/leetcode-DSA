class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n) ; 
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>> visited(n , vector<int>(k+1 , INT_MAX)) ; 
        priority_queue < pair <int , pair <int , int >> , vector <pair <int , pair <int , int >>> , greater <> >  pq; 
        pq.push({0 , {0 , 1}}) ; 
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first ; 
            int node = it.second.first ; 
            int conse = it.second.second ; 
            if(visited[node][conse] <= dist) continue ; 
            visited[node][conse] = dist ;
            // visited[node] = min(visited[node] ,dist) ; 
            for(auto next  : adj[node]){
                int nextnode = next.first ; 
                int curdist = next.second + dist ; 
                int newconse =1 ; 
                if(labels[nextnode] == labels[node]){
                    newconse = conse + 1 ; 
                }
                // else conse = 1 ; 
                if(newconse > k) continue ; 
                // visited[nextnode] = min(visited[nextnode] , curdist) ; 
                pq.push({curdist ,{nextnode , newconse }})  ; 
            }
        }
        int ans= *min_element(visited[n-1].begin() , visited[n-1].end()) ; 
        return (ans== INT_MAX) ? -1 : ans ;
    }
};