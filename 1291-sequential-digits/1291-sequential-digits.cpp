class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans ; 
        int n  = 9 ; 
        for(int i = 0 ; i< n ; i++){
            for(int j = i ; j < n ;j++){
                int num = 0 ; 
                int mult = 1 ; 
                for(int k = j ; k>= i ; k--){
                    num += (mult*(s[k] - '0')) ; 
                    mult *= 10 ; 
                }
                if(num <= high && num >= low ){
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin() , ans.end());
        
    return ans; 

    }
};