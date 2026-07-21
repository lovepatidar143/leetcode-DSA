class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin() , beans.end()) ; 
        
        long long remove = LLONG_MAX , bag = 0  ; 
        int n = beans.size() ; 
        vector<long long > prev(n) ; 
        prev[0] = beans[0] ; 
        for(int i =1 ; i< n ; i++){
            prev[i] = prev[i-1] + beans[i] ; 
        }

        for(int i = 0 ; i < n ; i++){
            long long dump = prev[i] - beans[i] ; 
            long long eql =  (1LL - 1LL + prev[n-1] -  prev[i] - 1LL*(n-i-1)*beans[i]) ; 
            remove = min(remove , dump + eql) ; 
        }


        return remove ; 
    }
};