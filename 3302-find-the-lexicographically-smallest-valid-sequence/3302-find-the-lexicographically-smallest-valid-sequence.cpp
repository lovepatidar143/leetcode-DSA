class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> matched(n, 0);

        int match = 0;
        int i = n - 1;
        int j = m - 1;

        // matched[i] = how many characters of word2
        // can be matched from word1[i...n-1]
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                match++;
                j--;
            }

            matched[i] = match;
            i--;
        }

        while (i >= 0) {
            matched[i] = match;
            i--;
        }

        vector<int> ans;

        bool canMismatch = true;

        i = 0;
        j = 0;

    
        while (i < n && j < m) {

            // Exact match
            if ( word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }


            // Use our one allowed mismatch
            else if (canMismatch && i < n-1 && matched[i+1] >= m - j - 1) {
                ans.push_back(i);
                canMismatch = false;
                j++;
            }

            i++;
        }

        if (j != m)
            return {};

        return ans;
    }
};