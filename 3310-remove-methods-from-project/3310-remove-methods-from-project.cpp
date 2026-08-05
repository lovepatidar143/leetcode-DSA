class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans ; 
        vector<vector<int>> adj(n) ;
        vector<int> visited(n , 0) ; 
        vector<int> inDegree(n,0) ;
        for(auto it: invocations){
            adj[it[0]].push_back(it[1]) ; 
            inDegree[it[1]]++;
        }
        queue<int> qu ; 
        qu.push(k) ; 
        while(!qu.empty()){
            int it = qu.front() ; 
            qu.pop() ; 
            visited[it] =1 ; 
            for(auto next : adj[it]){
                inDegree[next]--;
                if(!visited[next]){
                    qu.push(next) ; 
                    visited[next] =1 ; 
                }
            }
        }
        bool canremove = true ; 
        for(int i = 0 ; i< n ; i++){
            if(visited[i] == 1 && inDegree[i]>=1) {
                canremove = false ;
                break ;
            }
        }

        if(canremove){
            for(int i = 0 ; i< n ; i++){
                if(visited[i] == 0) ans.push_back(i) ;
            }
        }else {
            for(int i = 0 ; i< n ;i++) ans.push_back(i) ; 
        }

        return ans ; 

    }
};