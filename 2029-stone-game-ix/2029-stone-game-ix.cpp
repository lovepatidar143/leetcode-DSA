class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int one  = 0, two = 0 , three = 0 ;
        for(int i = 0 ; i< stones.size() ; i ++) {
            if(stones[i] %3 == 1) one++ ; 
            else if(stones[i]%3 == 2) two ++ ;
            else three++; 
        }
        int n = stones.size() ; 
       if (three % 2 == 0) {

            return one > 0 && two > 0;

        }



        return abs(one - two) > 2;
    }
};