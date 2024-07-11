#include <vector>
#include <algorithm>
using namespace std;

int f(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp){
    if(ind == n || cap == 0) return 0;

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    if(buy){
        return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices, n, dp), 
                                        0 + f(ind+1, 1, cap,prices, n, dp));
    }else{
        return dp[ind][buy][cap] = max(prices[ind] + f(ind+1,1,cap-1,prices, n, dp), 
                                        0 + f(ind+1, 0, cap,prices, n, dp));
    }
}

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, n, dp);
}

//Tabulation
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy) {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 
                                            dp[ind + 1][1][cap]);
                } else {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], 
                                            dp[ind + 1][0][cap]);
                }
            }
        }
    }
    
    return dp[0][1][2];
}

//Space optimisation
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
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
    
    return after[1][2];
}
