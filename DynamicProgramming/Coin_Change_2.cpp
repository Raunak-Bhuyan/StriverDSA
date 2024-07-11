#include<bits/stdc++.h>

int f(int ind, int value,int *denominations){
    if(ind == 0){
        return (value%denominations[ind] == 0);
        else return 0;
    }

    int not_take = 0 + f(ind - 1, value, denominations);
    int take = 0;
    if(denominations[ind] <= value) take = f(ind,value - denominations[ind],denominations);

    return (take + not_take);
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    return f(n-1, value, denominations);
}

//memoization
#include<bits/stdc++.h>

int f(int ind, int value,int *denominations, vector<vector<int>> &dp){
    if(ind == 0){
        return (value%denominations[ind] == 0);
    }
    if(dp[ind][value] != -1) return dp[ind][value];

    int not_take = 0 + f(ind - 1, value, denominations, dp);
    int take = 0;
    if(denominations[ind] <= value) take = f(ind,value - denominations[ind],denominations, dp);

    return dp[ind][value] = (take + not_take);
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<int>> dp(n, vector<int>(value+1, -1));
    return f(n-1, value, denominations, dp);
}


//Tabulation
#include<bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<int>> dp(n, vector<int>(value+1, 0));

    for(int v = 0; v<=value; v++) dp[0][v] = (v % denominations[0] == 0);

    for(int ind = 1; ind<n;ind++){
        for(int v = 0; v<=value; v++){
                int not_take = dp[ind - 1][v];
                int take = 0;
                if(denominations[ind] <= v) take = dp[ind][v - denominations[ind]];

                dp[ind][v] = (take + not_take);
        }
    }
    return dp[n-1][value];
}

//space optimisation
#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<long> prev(value + 1, 0), curr(value + 1, 0);

    // Initialize the base case
    for(int v = 0; v <= value; v++) {
        prev[v] = (v % denominations[0] == 0);
    }

    for(int ind = 1; ind < n; ind++) {
        for(int v = 0; v <= value; v++) {
            long not_take = prev[v];
            long take = 0;
            if(denominations[ind] <= v) {
                take = curr[v - denominations[ind]];
            }
            curr[v] = take + not_take;
        }
        // Move the current row to previous for the next iteration
        prev = curr;
    }

    return prev[value];
}
