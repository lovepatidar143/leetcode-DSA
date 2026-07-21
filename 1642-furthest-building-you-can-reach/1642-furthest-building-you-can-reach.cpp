class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size() ; 
        priority_queue < int > pq ; 
        int cnt = 0 ; 
        
        int prev = 0 ; 
        int ans = 0 ; 
        for(int i = 0 ; i< n ;i ++){
            if(heights[prev] - heights[i] >= 0) {
                prev = i ;
                ans = i ;  
                continue ; 
            }
            int jump = heights[i] - heights[prev] ;
            prev = i ;  
            if(bricks >= jump){
                bricks -= jump ;
                ans=i;
                pq.push(jump) ; 
            }
            else if(ladders > 0){
                // ladders--;
                pq.push(jump);
                bricks -= jump ;
                while(!pq.empty() && ladders > 0 && bricks < 0) {
                    bricks += pq.top(); 
                    ladders--;
                    pq.pop() ; 
                }
                if(bricks < 0){
                    ans = prev ;
                    break ;
                }
                else ans = i ; 
                
            }
            else {
                ans = i -1 ; 
                break ;
            }
        }
        return ans ; 

        
    }
};