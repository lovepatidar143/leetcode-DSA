class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1) ; 
        for(auto it : roads){
            //bidectional road
            adj[it[0]].push_back({it[1] , it[2]}) ; 
            adj[it[1]].push_back({it[0] , it[2]}) ; 
        }
        // adjecenty list is done ,
        using P = pair <int , int > ; // node , dist
        priority_queue < P , vector<P> , greater<>> pq ; 
        pq.push({INT_MAX , 1}) ; 
        int ans = INT_MAX ; 
        vector<int> distance(n+1 , INT_MAX); 
        // distance[1] = INT_MAX ; 
        while(!pq.empty()){
            auto [dist , node] = pq.top() ; 
            pq.pop() ; 
            if(node == n) {
                ans = min(ans , dist) ; 
            }
            for(auto it : adj[node]){
                int newNode = it.first ;
                int value = min(it.second , dist)  ; 
                if(distance[newNode] > value){
                    distance[newNode] = value  ; 
                    pq.push({value , newNode}) ;
                }
            }
        }
        return ans ; 
    }
};