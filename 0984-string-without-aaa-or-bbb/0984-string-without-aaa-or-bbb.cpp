class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "" ; 
        while(a!=0 && b!= 0 && a > b){
            if(a -b > 1) {
                ans+="aab"; 
                a -=2 ; 
                b --;
            }
            else {
                ans +="ab" ; 
                a--;
                b--;
            }
            
        }
        while(a!=0 && b!= 0 && b > a){
            if(b-a > 1) {
                ans += "bba";
                b-=2 ; 
                a--;
            }
            else{
                ans += "ba";
                b--;
                a--;
            }
        }
        while(a!=0 && b!=0){
            ans +="a";
            ans += "b";
            a--;
            b--;
        }
        while(a--) ans+= "a" ; 
        while(b--) ans +="b";
        return ans; 
    }
};