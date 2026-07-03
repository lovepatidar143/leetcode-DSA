class Solution {
public:
    bool solve(vector<vector<pair <int , int >> > &adj , int mid , long long k , vector<bool> & online){
        // using T = tuple < long long , int > ; 
        using T = pair < long long , int > ;

        int n = adj.size() ; 
        vector<long long> distArr(n , LLONG_MAX) ; 
        priority_queue < T , vector<T> , greater <> > pq ; 
        pq.push({0 , 0 }) ; 
        distArr[0] = 0 ; 
        while(!pq.empty()){
            auto [dist , node] = pq.top() ; 
            pq.pop() ;
            if(dist != distArr[node]) continue ; 
            //chck if its work
            if(node == n-1) {
                if(dist <= k) return true ; 
                else continue ; 
            }
            if(dist >= k) continue  ; 
            for(auto it : adj[node]){
                int desti = it.first ; 
                int cost = it.second ; 
                if(!online[desti]) continue ; 
                if(cost <mid) continue ; 
                // if(desti)
               if(distArr[desti] > dist + cost){
                    distArr[desti] = dist + cost ; 
                    pq.push({distArr[desti] , desti}) ; 
               }
            }
        }
        return false ; 
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(); 
        vector< vector<pair <int, int > >> adj(n) ; 
        int high = 0 ; 
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]}) ; 
            high = max(high , it[2]) ; 
        }

        if (!solve(adj, 0, k, online)) return -1;
        // done 
        int low = 0 ; 
        while(low < high){
            // int mid = (low + high) /2 ;
            int mid = low + (high - low + 1) /2 ; 
            bool check = solve(adj , mid , k , online ) ; 
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