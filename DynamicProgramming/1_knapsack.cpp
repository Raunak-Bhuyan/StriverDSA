#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &weight, vector<int> &value, int ind, int maxWeight, vector<vector<int>> &dp) {
    if (ind < 0) return 0;
    if (dp[ind][maxWeight] != -1) return dp[ind][maxWeight];

    int not_take = f(weight, value, ind-1, maxWeight, dp);
    int take = INT_MIN;
    if (weight[ind] <= maxWeight)
        take = value[ind] + f(weight, value, ind-1, maxWeight - weight[ind], dp);

    return dp[ind][maxWeight] = max(not_take, take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return f(weight, value, n-1, maxWeight, dp);
}


//Tabulation (bottom-up approach)
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    for(int w = weight[0]; w<=maxWeight; w++) dp[0][w] = value[0];

    for(int ind = 1; ind < n; ind++){
        for(int w=0; w<= maxWeight; w++){
           int not_take = dp[ind-1][w];
           int take = INT_MIN;
            if (weight[ind] <= w)
            take = value[ind] + dp[ind-1][w - weight[ind]];

            dp[ind][w] = max(not_take, take); 
        }
    }
    return dp[n-1][maxWeight];
}


//Space optimisation
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev(maxWeight+1,0), curr(maxWeight+1,0);
    for(int w = weight[0]; w<=maxWeight; w++) prev[w] = value[0];

    for(int ind = 1; ind < n; ind++){
        for(int w=0; w <= maxWeight; w++){
           int not_take = prev[w];
           int take = INT_MIN;
            if (weight[ind] <= w)
            take = value[ind] + prev[w - weight[ind]];

            curr[w] = max(not_take, take); 
        }
        prev = curr;
    }
    return prev[maxWeight];
}