class Solution {
public:
    int beautySum(string s) {
        int n = s.size() ; 
        int ans = 0 ;
        for(int i = 0 ; i < n ;i++){
            // priority_queue <pair <char, int >>
            unordered_map < char , int > hash ; 
            for(int j = i ; j < n ; j++){
                hash[s[j]]++ ;
                int maxi = INT_MIN , mini = INT_MAX ; 
                for(auto & it : hash){
                    maxi = max(maxi , it.second) ; 
                    mini = min(mini , it.second) ; 
                }
              
                ans += (maxi - mini) ; 
            }
        }
        return ans ; 
    }
};