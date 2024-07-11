#include<bits/stdc++.h>
using namespace std;

int f(int ind, int k){
    if(ind == 0)
        return o;

    min_steps = INT_MAX;
    for(int j=1; j<=k; j++){
        if(ind-j >= 0){
            int jumps = f(ind-j) + abs(heights[ind] - heights[ind-j]);
            min_steps = min(min_steps, jumps);
        }
    }
    return min_steps;
}

int FrogJumps(int n, vector<int> &heights){
    int k;
    cin >> k;
    return f(n-1, k, heights);
}

/***************************  Memoization ********************
vector<int> dp(n);
dp[0] = 0;
for(int i=1; i<n; i++){
    int min_steps = INT_MAX;
    for(int j=1; j<=k; j++){
        if(i-j >= 0){
            jumps = dp[i-j] + abs(heights[ind] - heights[ind-j]);
            min_steps = min(min_steps, jumps);
        }
        dp[i] = min_steps;
    }
    return dp[n-1];
}
*/
