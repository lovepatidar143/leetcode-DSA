class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26 , 0) ;  
        for(auto ch : word){
            hash[ch - 'a']++;
        }
        sort(hash.begin() , hash.end() ) ; 
        int cnt = 0 ; 
        int num = 8 ; 
        for(int i = 25 ; i>= 0 ; i--){
            if(hash[i] == 0) continue ; 
            cnt += (num/8)*(hash[i]) ; 
            num++;

        }
        return cnt ; 
    }
};