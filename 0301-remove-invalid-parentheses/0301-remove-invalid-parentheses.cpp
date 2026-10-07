class Solution {
public:
    int n;
    set<string> ans;

    void solve(const string &s, string &p, int i,
               int lcnt, int rcnt,
               int leftRemove, int rightRemove) {

        if (i == n) {
            if (lcnt == rcnt &&
                leftRemove == 0 &&
                rightRemove == 0) {
                ans.insert(p);
            }
            return;
        }

        // '('
        if (s[i] == '(') {

            // Remove '('
            if (leftRemove > 0) {
                solve(s, p, i + 1,
                      lcnt, rcnt,
                      leftRemove - 1,
                      rightRemove);
            }

            // Keep '('
            p.push_back('(');

            solve(s, p, i + 1,
                  lcnt + 1, rcnt,
                  leftRemove, rightRemove);

            p.pop_back();
        }

        // ')'
        else if (s[i] == ')') {

            // Remove ')'
            if (rightRemove > 0) {
                solve(s, p, i + 1,
                      lcnt, rcnt,
                      leftRemove,
                      rightRemove - 1);
            }

            // Keep ')' only if it is valid
            if (lcnt > rcnt) {

                p.push_back(')');

                solve(s, p, i + 1,
                      lcnt, rcnt + 1,
                      leftRemove, rightRemove);

                p.pop_back();
            }
        }

        // Normal character
        else {

            p.push_back(s[i]);

            solve(s, p, i + 1,
                  lcnt, rcnt,
                  leftRemove, rightRemove);

            p.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.size();

        int leftRemove = 0;
        int rightRemove = 0;

        // Find the minimum removals required
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string p = "";

        solve(s, p, 0,
              0, 0,
              leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};