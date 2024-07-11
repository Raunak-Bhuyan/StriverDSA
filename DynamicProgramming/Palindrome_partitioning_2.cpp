bool isPalindrome(string s){
    int n = s.size();
    int i=0;
    while(i<n){
        if(s[i] != s[n-i-1]) return false;
        i++;
    }
    return true;
}


int f(int i, int n,string &str, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    string temp = ""; int minCost = 1e9;
    for(int j=i; j<n; j++){
        temp += str[j];
        if (isPalindrome(temp)) {
          int cost = 1 + f(j + 1, n, str, dp);
          minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.size();
    vector<int> dp(n,-1);
    return f(0,n,str,dp) - 1; //subtracting 1 because we have to eliminate the partition at the end i.e. at the nth position.
}

//Tabulation
bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int minCost = 1e9;
        for (int j = i; j < n; j++) {
            if (isPalindrome(str, i, j)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1; // Subtracting 1 because we have to eliminate the partition at the end i.e. at the nth position.
}