int f(int ind, int buy, vector<int> &prices){
    if(ind >= prices.size()) return 0;

    if(buy){
        return max(-prices[ind] + f(ind + 1, 0, prices),
                    0 + f(ind+1, 1, prices));
    }else{
        return max(prices[ind] + f(ind+2,1,prices),
                    0 + f(ind+1,0,prices));
    }
}

int stockProfit(vector<int> &prices){
    // Write your code here.
    return f(0,1,prices);
}

//memoization
int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
    if(ind >= prices.size()) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy){
        return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, dp),
                    0 + f(ind+1, 1, prices, dp));
    }else{
        return dp[ind][buy] = max(prices[ind] + f(ind+2,1,prices, dp),
                    0 + f(ind+1,0,prices, dp));
    }
}

int stockProfit(vector<int> &prices){
    // Write your code here.
    vector<vector<int>> dp(prices.size()+1, vector<int> (2,-1));
    return f(0,1,prices, dp);
}

//Tabulation
int stockProfit(vector<int> &prices) {
    // Handle the edge case where prices is empty
    int n = prices.size();
    if (n == 0) return 0;

    
    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            } else {
                dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
            }
        }
    }

    return dp[0][1];
}

//Space optimised
int stockProfit(vector<int> &prices) {
    // Handle the edge case where prices is empty
    int n = prices.size();
    if (n == 0) return 0;

    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> curr(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        
            
                curr[1] = max(-prices[ind] + front1[0], 0 + front1[1]);
            
                curr[0] = max(prices[ind] + front2[1], 0 + front1[0]);
            
    front2 = front1;
    front1 = curr;
    }


    return curr[1];
}
