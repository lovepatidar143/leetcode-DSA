class Solution {
public:
    void dfs(int node , int parent , vector<vector<int>> &adj , vector<int> &tin , vector<int>&low ,vector<int> & v , vector<vector<int>> & cc , int &timer ){
        v[node] =1 ; 
        tin[node] = low[node] = timer ; 
        timer ++ ; 
        for(auto it : adj[node]){
            if(it== parent) continue ;
            if(!v[it]){
                dfs(it , node , adj , tin , low , v , cc , timer) ; 
                low[node] = min(low[node] , low[it]) ; 
                if(tin[node] < low[it]){
                    cc.push_back({it , node}) ; 
                }
            }
            else {
                low[node] = min(low[node] , low[it]) ;
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n) ; 
        for(auto it : connections){
            adj[it[0]].push_back(it[1]) ; 
            adj[it[1]].push_back(it[0]) ; 
        }

        vector<vector<int>> cc ; 
        vector<int> tin(n) , low(n) , v(n , 0) ;
        int timer = 0 ; 
        for(int i = 0 ; i< n ; i++){
            dfs(i , -1 , adj , tin , low , v , cc , timer ) ; 
        }
        return cc ; 
    }
};