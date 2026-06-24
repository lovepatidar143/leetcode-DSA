class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {

            while(!st.empty() && 
                 (i == n || arr[st.top()] >= arr[i])) {

                int height = arr[st.top()];
                st.pop();

                int nse = i;  
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size() ; 
        int col = matrix[0].size() ; 

        vector<vector<int>> height(row , vector<int> (col, 0)) ; 

        // height[0] = matrix[0] ; 
        for(int i =0 ; i < row ; i++){

            for(int j = 0 ; j < col ; j++){
                if(i==0){
                    height[i][j] = matrix[i][j] -'0'  ; 
                    continue ;
                }
                if(matrix[i][j] == '1'){
                    height[i][j]  = height[i-1][j] +1 ;

                }
                else height[i][j] =0 ;
            }
        }

        int ans = INT_MIN ; 
        for(int i= 0 ; i < row ; i++){
            int area = largestRectangleArea(height[i]) ; 
            ans = max(area , ans) ; 
        }
        return ans ; 

    }
};