class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26 , 0) ; 
        for(auto ch : word) hash[ch -'a']++;
        int n = 8 ; 
        int ans = 0 ; 
        sort(hash.begin() , hash.end()) ; 
        for(int i = 25 ; i>=0 ; i--){
            if(hash[i] == 0) break ; 
            ans+=( n/8)*hash[i] ; 
            n++;
        }
        return ans ; 
    }
};