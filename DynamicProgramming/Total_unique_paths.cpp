#include <bits/stdc++.h>

int f(int m, int n) {
    if (m == 0 && n == 0)
        return 1;

    if (m < 0 || n < 0)
        return 0;

    int up = f(m - 1, n);
    int left = f(m, n - 1);

    return up + left;
}

int uniquePaths(int m, int n) {
    return f(m - 1, n - 1);
}

/*********************   Memoization   *********************/

/*
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

*/