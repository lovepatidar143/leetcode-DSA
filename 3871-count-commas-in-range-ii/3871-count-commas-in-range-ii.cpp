class Solution {
public:
    long long countCommas(long long n) {
        int digi = 0 ;
        long long t = n ; 
        while(t){
            digi++;
            t = t/10;
            
        }
        if(digi<4) return 0;
        long long ans = 0 ;
        for(int i = 4 ; i<digi ; i++){
            long long cnt = 9 ; 
            long long  num = pow(10 , i-1);
            cnt = cnt*num;
            int place = 0;
            if(i%3 == 0) place = i/3-1;
            else place = i/3;
            ans+= cnt*place;
        }
        long long num = pow(10, digi - 1);
        int place = 0 ;
        if(digi%3 == 0) place = digi/3-1;
        else place = digi/3;
        ans+= (n-num+1)*place;
        return ans;
    }
};