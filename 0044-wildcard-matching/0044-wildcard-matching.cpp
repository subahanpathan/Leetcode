class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> dp(m + 1, false);
        dp[0] = true;

        // Empty string can match only a pattern consisting entirely of '*'
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[j] = dp[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            vector<bool> newDp(m + 1, false);

            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    // '*' matches empty OR one/more characters
                    newDp[j] = newDp[j - 1] || dp[j];
                }
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    newDp[j] = dp[j - 1];
                }
            }

            dp = newDp;
        }

        return dp[m];
    }
};