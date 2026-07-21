class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair <int , int>> v; 
        int n = s.size() ; 
        int cur =1 ; 
        char prev = s[0] ; 
        for(int i =1 ; i< n ; i++){
            if(prev == s[i]) cur++;
            else {
                v.push_back({cur , prev -'0'}) ; 
                cur = 1 ; 
                prev = s[i] ;
            }
        }

        v.push_back({cur , prev -'0' }) ; 
        int m = v.size() ; 
        vector<int> cnt(m) ; 
        int ans = 0 ; 
        int ma = 0 ;
        for(int i = 0 ; i< m ; i++){
            if(i == 0 || i == m-1){
                if(v[i].second == 1) ans += v[i].first ; 
                continue ; 
            }
            else ans += (v[i].first * v[i].second); 

            if(v[i].second ==  1) ma = max(ma , v[i-1].first + v[i+1].first) ; 
            
        }
        ans += ma ; 

        // ans = max()


        return ans ; 

    }
};