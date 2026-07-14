class Solution {
public:
    bool dfs(vector < vector<int>> & adj , vector<int> & visit , int node , int &m , int &e ){
        visit[node] =1 ; 
        bool ans = true; 
        m++;
        for(auto it : adj[node]){
            if(it < node) e++; 
            if(!visit[it]) {
                
                if(!dfs(adj , visit , it , m , e )) {
                    ans =  false ;
                } 
            }
        }
        if(m != adj[node].size()) return false ; 
        return ans ; 
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0 ; 
        vector<vector<int>> adj(n) ; 
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ; 
            adj[it[1]].push_back(it[0]) ; 
        }
        int cnt = 0 ; 
        vector<int> visit(n , 0) ; 
        for(int i = 0 ; i< n ; i++){
            if(visit[i]) continue ; 
            int m = 0; 
            int e= 0 ; 

            if(dfs(adj , visit , i , m , e)) ; 
            if(m*(m-1)/2 == e) ans ++ ; 
            cnt ++ ; 
        }
        return ans; 
    }
};