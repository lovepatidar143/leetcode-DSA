class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int sum = 0;

        int ans = 0;
        int diff = INT_MAX;

        for (int i = 0; i < n; i++) {
            int rest = n - i;
            int need = (target - sum) / rest;

            if (need < arr[i]) {
                int total = sum + need * rest;
                int currDiff = abs(total - target);

                if (currDiff < diff) {
                    diff = currDiff;
                    ans = need;
                }
                else if (currDiff == diff) {
                    ans = min(ans, need);
                }


                int total2 = sum + (need + 1) * rest;
                int currDiff2 = abs(total2 - target);

                if (currDiff2 < diff) {
                    diff = currDiff2;
                    ans = need + 1;
                }
                else if (currDiff2 == diff) {
                    ans = min(ans, need + 1);
                }

                return ans;
            }

            sum += arr[i];
        }

        return arr[n - 1];
    }
};