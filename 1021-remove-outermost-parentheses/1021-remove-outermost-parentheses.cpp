class Solution {
public:
    string removeOuterParentheses(string s) {
        string t = "";
        int count = 0 ;
        int n = s.size();
        for(int i = 0 ; i < n ; i ++){
            
            if(s[i]=='(') {
                if (count > 0) t+= s[i];
                count ++;
            }
            else {
                count--;
                if (count > 0) t+= s[i];
            }
            
        }
        return t;
    }
};