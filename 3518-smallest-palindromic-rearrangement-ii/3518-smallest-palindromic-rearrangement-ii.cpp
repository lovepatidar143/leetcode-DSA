class Solution {
public:
    long long LIMIT;

    // Calculate nCr but stop if it exceeds k
    long long comb(long long n, long long r) {
        r = min(r, n - r);

        long long res = 1;

        for (long long i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;

            if (res >= LIMIT)
                return LIMIT;
        }

        return res;
    }


    // Count number of unique permutations of remaining half
    long long countWays(vector<int>& freq) {

        long long ans = 1;
        int rem = 0;

        for (int x : freq)
            rem += x;


        // Multinomial:
        // rem! / (f1! f2! ...)
        // = C(rem,f1)*C(rem-f1,f2)*...
        for (int x : freq) {

            if (x == 0)
                continue;

            ans *= comb(rem, x);

            if (ans >= LIMIT)
                return LIMIT;

            rem -= x;
        }

        return ans;
    }


    string smallestPalindrome(string s, int k) {

        LIMIT = k;

        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;


        char mid = '#';

        // Convert to frequency of left half
        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2)
                mid = char('a' + i);

            freq[i] /= 2;
        }


        // Total possible palindromes
        long long total = countWays(freq);

        if (total < k)
            return "";


        string left = "";

        int len = s.size() / 2;


        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (freq[c] == 0)
                    continue;


                // Try putting this character
                freq[c]--;


                long long cnt = countWays(freq);


                if (k > cnt) {

                    // Skip these cnt permutations
                    k -= cnt;

                    freq[c]++;

                }
                else {

                    // This character belongs here
                    left.push_back(char('a' + c));
                    break;

                }
            }
        }


        string right = left;
        reverse(right.begin(), right.end());


        if (mid != '#')
            return left + mid + right;

        return left + right;
    }
};