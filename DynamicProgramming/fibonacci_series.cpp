#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& dp){
    if(n <= 1)
        return n;
    
    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);  // Correctly initialize the dp vector
    cout << f(n, dp);
    return 0;
}

//space optimisation 

/*
int prev1 = 1;
int prev2 = 0;
for(int i=2; i<=n; i++){
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
    }
    cout << prev;
*/