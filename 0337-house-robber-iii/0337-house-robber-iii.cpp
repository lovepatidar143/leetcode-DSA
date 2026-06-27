/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode * node , bool canRob , unordered_map < TreeNode * , vector<int>> &dp){
        if(!node) return 0 ; 
        if(dp[node][canRob] != -1) return dp[node][canRob] ;
        int robe = 0 , dontRobe = 0 ;
        if(canRob){
            robe = node -> val + (solve(node -> left , false ,dp ) + solve(node -> right , false ,dp)) ; 

        }
        dontRobe = (solve(node -> right , true ,dp) + solve(node -> left , true ,dp)) ; 
        return dp[node][canRob] =  max(robe , dontRobe) ; 
    }

    void map_dp(unordered_map <TreeNode * , vector <int>> &dp , TreeNode * node){
        if(!node) return ;

        // go left 
        dp[node] = {-1 , -1 } ;
        map_dp(dp , node -> left) ; 
        map_dp(dp , node -> right) ; 
        // go right
    }
    int rob(TreeNode* root) {
        unordered_map < TreeNode * , vector<int> > dp ; 
        map_dp(dp , root) ; 
        return solve(root , true , dp) ; 
    }
};