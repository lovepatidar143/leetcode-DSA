class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0 ; 
        int mask = 0 ; 
        unordered_map < int , long long > hash ; 
        hash[0] = 1 ;
        for(auto ch : word){
            mask ^= (1<<(ch -'a')) ; 
            ans += hash[mask] ;
            for(int i = 0 ; i < 10 ; i++){
                ans += hash[mask ^ (1<<i)] ;
            }
            hash[mask]++;
        }

        return ans ; 
    }
};