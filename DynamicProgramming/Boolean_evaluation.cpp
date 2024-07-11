int mod = 1000000007;

long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) {
            return exp[i] == 'T';
        } else {
            return exp[i] == 'F';
        }
    }
    if (dp[i][j][isTrue] != -1) {
        return dp[i][j][isTrue];
    }

    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        long long leftTrue = f(i, ind - 1, 1, exp, dp);
        long long leftFalse = f(i, ind - 1, 0, exp, dp);
        long long rightTrue = f(ind + 1, j, 1, exp, dp);
        long long rightFalse = f(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            } else {
                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        } else if (exp[ind] == '|') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            } else {
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
            }
        } else if (exp[ind] == '^') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            } else {
                ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}