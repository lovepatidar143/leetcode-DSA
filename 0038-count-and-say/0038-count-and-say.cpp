class Solution {
public:
    string RLE(string &s){
        string ans = "" ; 
        char prev = s[0] ; 
        int cnt = 1 ; 
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] == prev) cnt++ ; 
            else {
                ans += (cnt + '0') ; 
                ans += prev ; 
                prev = s[i];
                cnt = 1 ; 
            }
        }
        ans += (cnt +'0');
        ans += prev ; 
        return ans ; 
   }
    string countAndSay(int n) {
        vector <string > dp(n +1) ; 
        dp[1] = '1' ; 
        for(int i = 2 ; i <= n ; i++){
            dp[i] = RLE(dp[i-1]) ; 
        }

        return dp[n] ; 

    }
};