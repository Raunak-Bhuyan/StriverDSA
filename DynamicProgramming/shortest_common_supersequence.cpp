#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Compute length of LCS using dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the shortest supersequence
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            ans += s[i - 1];
            --i;
        } else {
            ans += t[j - 1];
            --j;
        }
    }

    // Add remaining characters of s
    while (i > 0) {
        ans += s[i - 1];
        --i;
    }

    // Add remaining characters of t
    while (j > 0) {
        ans += t[j - 1];
        --j;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}