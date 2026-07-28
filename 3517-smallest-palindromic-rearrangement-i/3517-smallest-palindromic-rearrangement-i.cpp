class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size() ; 
        vector<int> hash(26 ,0) ; 
        for(auto ch : s){
            hash[ch - 'a']++;
        }

        string ans = ""; 
        string last = "" ;
        for(int i = 0 ; i< 26 ; i++){
            if(hash[i]%2 == 1){
                last = i + 'a' ; 
            }
            ans += string(hash[i]/2 , i + 'a') ; 
        }


        if(n%2 == 0){
            string temp = ans ; 
            reverse(ans.begin(),ans.end()) ;
            temp += ans ; 
            ans = temp ; 

         
        }
        else {
            string temp = ans + last ;
            reverse(ans.begin() , ans.end()) ; 
            temp = temp + ans ; 
            ans = temp ;
        }
        return ans; 
    }
};