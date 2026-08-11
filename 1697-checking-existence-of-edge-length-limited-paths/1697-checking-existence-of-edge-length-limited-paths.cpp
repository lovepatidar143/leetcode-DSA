class Dsu{
    public : 
    vector<int> par ; 

    Dsu(int n ){
        par.resize(n);
        for(int i = 0 ;i< n ; i++) par[i] = i ; 
    }
    
    int parent(int i){
        if(par[i] == i) return i; 
        par[i] = parent(par[i]) ; 
        return par[i] ;
    }
    void join(int v , int u){
        int pu = parent(u) ; 
        int pv = parent(v)  ; 
        par[pu] = pv ; 
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n,
     vector<vector<int>>& edgeList, 
     vector<vector<int>>& queries) {
        // vector<vector<pair <int , int>>>    adj(n) ;  
        // for(auto it : edgeList){
        //     adj[it[0]].push_back({it[1] , it[2]}) ; 
        //     adj[it[1]].push_back({it[0] , it[2]}) ; 

        // }

        Dsu dsu(n) ; 
        for(int i = 0 ; i < queries.size() ; i++){
            queries[i].push_back(i) ; 
        }
        
        sort(queries.begin() , queries.end() , [](auto &l , auto & r) {return l[2] < r[2] ; }) ; 
        sort(edgeList.begin() , edgeList.end() , [](auto &l , auto &r) {return l[2] < r[2] ; }) ;
        int q = queries.size() ; 
        vector<bool> ans(q) ; 
        int j = 0 ;
        int m = edgeList.size() ; 
        for(int i = 0 ;i <  q ; i++){
            int target = queries[i][2] ; 
            while(j < m && edgeList[j][2] < target){
                dsu.join(edgeList[j][1] , edgeList[j][0]) ;
                j++;
            }
            if(dsu.parent(queries[i][1]) == dsu.parent(queries[i][0])){
                ans[queries[i][3]] = true ; 
            }
            else ans[queries[i][3]] = false ; 
        }
        return ans ;
    }
};