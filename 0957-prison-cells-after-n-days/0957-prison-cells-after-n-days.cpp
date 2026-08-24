class Solution {
public:
    int nextCell(int i , int num){
        if(i == 0 || i == 7) return 0 ; 
        bool set1 = (1<<(i-1))&num ; 
        bool set2 = (1<<(i+1))&num ; 
        if(set1 && set2 ) return 1 ; 
        if(!set1 && !set2) return 1 ; 
        return 0 ; 
    }
    int nextNum(int prev){
        int next = 0 ; 
        for(int i = 0; i <8 ; i++){
            int cell = nextCell(i , prev ) ;
            if(cell ==1) next = next | (1<<i) ; 
        }
        return next; 
    }
    vector<int> ans(int num){
        vector<int> res(8 , 0) ; 
        for(int i = 0 ; i< 8 ; i++){
            if(num&(1<<i)) res[7-i] = 1; 
        }
        return res ; 
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map <int , int > hash ; 
        vector<int> hasharr ; 
        int num = 0 ;
        for(int i = 0 ; i< 8 ; i++){
            if(cells[7-i] ==1) num = num | (1<<i) ; 
        }
        hasharr.push_back(num) ; 
        int p = 0 ; 
        hash[num] = p ;
        int next ; 
        int day = 0 ; 
        while(true){
            next = nextNum(num) ;
            day++;
            p++;
            if(day == n) return ans(next); 
            if(hash.find(next) != hash.end()){
                int start = hash[next] ; 
                int lenght = hasharr.size() - start ; 
                int ind =  start + (n-start)%lenght; 
                return ans(hasharr[ind]) ; 
            }
            else {
                hash[next] = p;
                hasharr.push_back(next) ; 
            }
            num = next; 
        }
        return ans(num) ; 
    }
};