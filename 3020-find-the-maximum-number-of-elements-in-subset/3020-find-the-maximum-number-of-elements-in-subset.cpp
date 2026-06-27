class Solution {
public:
    int MOD = 1e9 + 7 ; 
    int maximumLength(vector<int>& nums) {
        int n = nums.size() ; 
        unordered_map <long long , int > hash ; 
        for(int it : nums) hash[it]++ ; 

        int ans =1 ; 
        for(auto &[it, freq] : hash){
            long long find = it ; 
            
            if(it <= 1) {
                ans = max(ans , hash[it] - (hash[it] % 2 == 0)) ; 
                continue ; 
            }
            int cnt = 0 ; 
            while(true){
                if( hash.find(find) != hash.end() && hash[find] >=2){
                    // find = (find %MOD) * find ;
                    if(find >= 1000000000) break;
                    find  *= find ; 
                    cnt+= 2; 
                }
                else if(hash.find(find) != hash.end() && hash[find] == 1){
                    cnt += 1; 
                    break ; 
                }
                else {
                    // cnt+=2;
                    // cnt -- ;i
                    if(cnt% 2 == 0) cnt -- ; 
                    break ; 
                }
            }
            ans = max(ans , cnt ) ; 

        }
        return ans ; 
    }
};