int f(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if(ind == 0){
        return (w / weight[0]) * profit[0];
    }
    if(dp[ind][w] != -1) return dp[ind][w];

    int not_take = f(ind - 1, w, profit, weight, dp);
    int take = 0;
    if(weight[ind] <= w) take = profit[ind] + f(ind, w - weight[ind], profit, weight, dp);

    return dp[ind][w] = max(not_take, take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, profit, weight, dp);
}


//Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    // Base case: When only the first item is considered
    for (int wt = 0; wt <= w; wt++)
        dp[0][wt] = (wt / weight[0]) * profit[0];

    // Build the dp table in a bottom-up manner
    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {
            int not_take = dp[ind - 1][wt];
            int take = 0;
            if (weight[ind] <= wt) {
                take = profit[ind] + dp[ind][wt - weight[ind]];
            }
            dp[ind][wt] = max(not_take, take);
        }
    }
    return dp[n - 1][w];
}

//Space Optimisation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<int> prev(w+1, 0);
    vector<int> curr(w+1, 0);

    // Base case: When only the first item is considered
    for (int wt = 0; wt <= w; wt++)
        prev[wt] = (wt / weight[0]) * profit[0];

    // Build the dp table in a bottom-up manner
    for (int ind = 1; ind < n; ind++) {
        for (int wt = 0; wt <= w; wt++) {
            int not_take = prev[wt];
            int take = 0;
            if (weight[ind] <= wt) {
                take = profit[ind] + curr[wt - weight[ind]];
            }
            curr[wt] = max(not_take, take);
        }
        prev = curr;
    }
    return prev[w];
}
