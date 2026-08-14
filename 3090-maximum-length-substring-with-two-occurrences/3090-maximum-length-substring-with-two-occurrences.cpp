class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map < int , int > hash ; 
        int i = 0 , j = 0 ; 
        int n = s.size() ; 
        int ans = 1 ; 
        while(i < n){
            hash[s[i]]++;
            while(j < i && hash[s[i]] >2 ){
                hash[s[j]]--;
                j++;
            }
            ans = max(ans , i - j +1) ; 
            i++;
        }
        return ans ; 
    }
};