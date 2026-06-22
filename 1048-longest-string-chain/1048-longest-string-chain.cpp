class Solution {
public:
    static bool comp(string s , string t){
        return s.size() < t.size() ;
    }
    //assuje s2 > s1
    bool check(string & s1 , string & s2){
        bool flag = false ;
        int n = s2.size() ; 
        if(n == s1.size()) return false ; 
        int i = 0  , j = 0 ; 
        while(i < n && j < n){
            if(s1[i] == s2[j]){
                i++ , j++ ; 
                continue ; 
            }
            if(flag) return false ; 
            flag = true ; 
            j++;
        }
        return true ; 
        
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp) ; 
        int n = words.size();
        vector <int> dp(n ,1) ; 
        vector <int> hash(n) ; 
        int ind = 0 , cnt = 1 ; 
        for(int i = 0 ; i < n ; i++) hash[i] = i ; 
        for(int i = 0 ; i< n ; i++){
            for(int prev = 0 ; prev < i ; prev ++){
                if(check(words[prev] , words[i])){
                    if(dp[i] < dp[prev] +1 ){
                        dp[i] = dp[prev] +1 ; 
                        hash[i] = prev ; 
                    }
                }
            }
            if(dp[i] > cnt){
                cnt = dp[i] ; 
                ind = i ;
            }

        }
        vector < string > sol ; 
        sol.push_back(words[ind]) ; 
        while(ind != hash[ind]){
            ind = hash[ind] ; 
            sol.push_back(words[ind]);
        }
        // return sol ; 
        return cnt ; 
    }
};