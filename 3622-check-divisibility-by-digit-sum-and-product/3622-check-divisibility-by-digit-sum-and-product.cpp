class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 , pro =1 ; 
        int num = n ; 
        while(n>0){
            int digi = n%10 ; 
            n = n/10 ; 
            sum += digi ; 
            pro *= digi ;
        }
        // cout << sum << endl << pro << endl ; 
        sum = sum + pro ; 
        // cout << sum ; 
        if(num%sum == 0) return 1 ; 
        return false ; 
    }
};