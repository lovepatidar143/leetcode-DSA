class Solution {
public:
    bool checkValidString(string s) {
        int mi = 0 , ma = 0 ;
        for(auto ch : s){
            if(ch == '('){
                ma++;
                mi++;
            }
            else if(ch == ')'){
                ma--;
                 mi--;

            }else {
                 mi--;
                ma++;

            }
            if(mi <0) mi = 0;
            if(ma <0) return false ;
        }
        if(mi == 0) return true;
        return false ;
    }
};