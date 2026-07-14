class Solution {
public:
struct PairHash {

    size_t operator()(const pair<int, int>& p) const {

        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);

    }

};

// unordered_map<pair<int, int>, int, > mp;
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map <pair<int, int>  , int  ,PairHash> hash ; 
        vector<vector<int>> adj(n) ; 
        for(auto it : connections){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
            hash[{it[0] , it[1]}] ++; 
        }

        queue <int> qu ; 
        qu.push(0) ; 
        int cnt = 0 ; 
        vector<int> visited(n,0) ; 
        // visited[0] =1 ; 
        while(!qu.empty()){
            int node = qu.front() ; 
            qu.pop() ; 
            visited[node] =1 ; 
            for(auto it : adj[node]){
                if(visited[it]) continue ; 
                qu.push(it) ; 
                if(hash.find({node , it}) != hash.end()) cnt++ ; 
            }
        }
        return cnt ;
    }
};