class DSU{
    vector<int> rank ; 
    public : 
    vector<int> parent ; 
    DSU(int n ){
        parent.resize(n) ; 
        rank.resize(n , 1) ; 
        for(int i = 0 ; i< n ; i++) parent[i] = i ; 

    }

    int find(int i ){
        if(parent[i] == i) return i ; 
        return parent[i] = find(parent[i]);
    }
    void join(int u , int v) {
        int pu = find(u) ; 
        int pv = find(v) ; 
        if(rank[pu] < rank[pv]){
            parent[pu]  = pv ; 
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu ; 
        }
        else {
            parent[pu] = pv ; 
            rank[pv]++;
        }
    }

};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size() ;
        DSU  dsu(n)  ;
        vector<int> ans ; 
        vector<pair<int, int >> arr; 
        for(int i = 0 ; i< n;  i++){
            arr.push_back({nums[i] , i }) ; 
        }
        sort(arr.begin() , arr.end()) ; 
        for(int i = 1 ; i< n ; i++){
            if(arr[i].first - arr[i-1].first <= limit) dsu.join(arr[i].second , arr[i-1].second) ;
        }
        unordered_map < int , vector<int>> hash ; 
        for(int i = 0 ; i< n ; i++){
            hash[dsu.find(i)].push_back(nums[i]);
        }
        for(auto &it : hash) sort(it.second.begin() ,it.second.end());
        for(int i = 0 ; i < n ; i++){
            int x = dsu.find(i) ; 
            ans.push_back(hash[x][0]) ; 
            hash[x].erase(hash[x].begin());
        }
        return ans ; 
    }
};