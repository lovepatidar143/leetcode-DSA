/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2 , -1) ; 

        ListNode * cur = head ; 
        int prev = cur -> val ; 
        int ind = 0  , pind = -1 ,first = -1;
        cur = cur -> next ;
        while(cur -> next){
            if(cur->val > prev && cur -> val > cur -> next -> val){
                if(pind == -1) {
                    pind = ind ; 
                    first = ind; 
                }
                else {
                    if(ans[0] == -1) ans[0] = ind - pind ; 
                    else ans[0] = min(ans[0] , ind - pind) ; 
                    pind = ind ; 
                }
            }
            if(cur->val < prev && cur -> val < cur -> next -> val){
                if(pind == -1) {
                    pind = ind ; 
                    first = ind; 
                }
                else {
                    if(ans[0] == -1) ans[0] = ind - pind ; 
                    else ans[0] = min(ans[0] , ind - pind) ; 
                    pind = ind; 
                }
            }
            ind++;
            prev = cur -> val ; 
            cur = cur -> next ; 
        }
        if(ans[0] != -1) ans[1] = pind - first ;
        return ans ; 
    }
};