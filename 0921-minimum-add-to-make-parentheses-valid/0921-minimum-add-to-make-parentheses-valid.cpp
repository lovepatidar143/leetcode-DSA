class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0 ; 
        int ans = 0 ;
        for(auto ch : s ){
            if(ch == '('){
                if(cnt <0) cnt = 0  ;
                cnt ++ ; 
            }
            else {
                if(cnt <=0) ans ++ ;
                cnt -- ; 
            }
        }
        // ans += abs(cnt) ; 
        if(cnt > 0) ans += cnt ; 
        return ans ; 
    }
};