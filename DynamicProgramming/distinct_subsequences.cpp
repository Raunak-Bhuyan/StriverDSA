int f(int i, int j, string &str, string &sub){
	if(j<0) return 1;
	if(i<0) return 0;

	if(str[i] == sub[j]) return (f(i-1,j-1, str, sub) + f(i-1,j, str, sub));
	else return f(i-1,j, str, sub);
}

int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n = str.size();
	int m = sub.size();

	return f(n-1, m-1, str, sub);
}

//memoization

int f(int i, int j, string &str, string &sub, vector<vector<int>> &dp){
	if(j<0) return 1;
	if(i<0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	
	if(str[i] == sub[j]) return (f(i-1,j-1, str, sub, dp) + f(i-1,j, str, sub, dp));
	else return dp[i][j] = f(i-1,j, str, sub, dp);
}

int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n = str.size();
	int m = sub.size();
	vector<vector<int>> dp(n, vector<int> (m,-1));
	return f(n-1, m-1, str, sub, dp);
}


//1-based Indexing memoization
int f(int i, int j, string &str, string &sub, vector<vector<int>> &dp){
	if(j==0) return 1;
	if(i==0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	
	if(str[i-1] == sub[j-1]) return (f(i-1,j-1, str, sub, dp) + f(i-1,j, str, sub, dp));
	else return dp[i][j] = f(i-1,j, str, sub, dp);
}

int distinctSubsequences(string &str, string &sub)
{
	// Write your code here.
	int n = str.size();
	int m = sub.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
	return f(n, m, str, sub, dp);
}

//Tabulation
int distinctSubsequences(string &str, string &sub) {
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // If sub is an empty string, there's one subsequence of any string that matches: the empty subsequence
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    // If str is an empty string, and sub is not, there's no way to form sub from str
    for (int j = 1; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str[i - 1] == sub[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}