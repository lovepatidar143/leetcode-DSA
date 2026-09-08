class Solution {
public:
    int countCommas(int n) {
        int digi = 0 ;
        int t = n ; 
        while(t){
            digi++;
            t = t/10;
            
        }
        if(digi <4) return 0;
        return n - 1000 + 1;
    }
};