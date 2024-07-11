#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    
    if (n == 0) return 0;
    
    vector<vector<int>> after(2, vector<int>(k+1, 0));
    vector<vector<int>> curr(2, vector<int>(k+1, 0));
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy) {
                    curr[buy][cap] = max(-prices[ind] + after[0][cap], 
                                            after[1][cap]);
                } else {
                    curr[buy][cap] = max(prices[ind] + after[1][cap - 1], 
                                            after[0][cap]);
                }
            }
        }
        after = curr;
    }
    
    return after[1][k];  
}

//Another approach
#include <bits/stdc++.h> 

int f(int ind, int transactionNo, vector<int> &prices, int n, int k){
    if(ind == n || transactionNo == 2*k) return 0;

    if(transactionNo%2 == 0){
        return max(-prices[ind] + f(ind+1, transactionNo+1, prices, n, k),
                    0 + f(ind+1, transactionNo, prices, n, k));
    } else {
        return max(prices[ind] + f(ind+1, transactionNo+1, prices, n, k),
                    0 + f(ind+1, transactionNo, prices, n, k));
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    return f(0,0,prices,n,k);
}


//Memoization
#include <bits/stdc++.h> 

int f(int ind, int transactionNo, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
    if(ind == n || transactionNo == 2*k) return 0;
    if(dp[ind][transactionNo] != -1) return dp[ind][transactionNo];

    if(transactionNo%2 == 0){
        return dp[ind][transactionNo] = max(-prices[ind] + f(ind+1, transactionNo+1, prices, n, k, dp),
                    0 + f(ind+1, transactionNo, prices, n, k, dp));
    } else {
        return dp[ind][transactionNo] = max(prices[ind] + f(ind+1, transactionNo+1, prices, n, k, dp),
                    0 + f(ind+1, transactionNo, prices, n, k, dp));
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n, vector<int> (2*k,-1));
    return f(0,0,prices,n,k, dp);
}

//Tabulation
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n+1, vector<int> (2*k+1,0));
    
    for(int ind = n-1; ind>=0; ind--){
        for(int transactionNo=2*k-1; transactionNo >= 0; transactionNo--){
            if(transactionNo%2 == 0){
                 dp[ind][transactionNo] = max(-prices[ind] + dp[ind+1][transactionNo+1],
                    0 + dp[ind+1][transactionNo]);
            } else {
                     dp[ind][transactionNo] = max(prices[ind] + dp[ind+1][transactionNo+1],
                         0 + dp[ind+1][transactionNo]);
                 }            
        }
    }
    return dp[0][0]; 
}

//Space optimisation
#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int> after(2*k+1,0), curr(2*k+1,0);
    
    for(int ind = n-1; ind>=0; ind--){
        for(int transactionNo=2*k-1; transactionNo >= 0; transactionNo--){
            if(transactionNo%2 == 0){
                 curr[transactionNo] = max(-prices[ind] + after[transactionNo+1],
                    0 + after[transactionNo]);
            } else {
                     curr[transactionNo] = max(prices[ind] + after[transactionNo+1],
                         0 + after[transactionNo]);
                 }            
        }after = curr;
    }
    return after[0]; 
}

