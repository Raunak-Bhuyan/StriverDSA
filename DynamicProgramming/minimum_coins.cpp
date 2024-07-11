#include <bits/stdc++.h> 

int f(int ind, int T, vector<int> &num){
    if(ind == 0){
        if(T % num[0] == 0) return T/num[0];
        else return 1e9;
    }

    int notTake = 0 + f(ind-1, T, num);
    int Take = INT_MAX;
    if(num[ind] <= T) Take = 1 + f(ind, T-num[ind], num);

    return min(notTake,Take);
}
int minimumElements(vector<int> &num, int Target)
{
    // Write your code here.
    int n = num.size();
    int ans = f(n-1, Target, num);
    if(ans >= 1e9) return -1;
    else return ans;
}

//memoization
#include <bits/stdc++.h> 
int f(int ind, int T, vector<int> &num,vector<vector<int>> &dp){
    if(ind == 0){
        if(T % num[0] == 0) return T/num[0];
        else return 1e9;
    }
    if(dp[ind][T] != -1) return dp[ind][T];

    int notTake = 0 + f(ind-1, T, num, dp);
    int Take = INT_MAX;
    if(num[ind] <= T) Take = 1 + f(ind, T-num[ind], num, dp);

    return dp[ind][T] = min(notTake,Take);
}
int minimumElements(vector<int> &num, int Target)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (Target+1,-1));
    int ans = f(n-1, Target, num, dp);
    if(ans >= 1e9) return -1;
    else return ans;
}

//Tabulation 
#include <bits/stdc++.h> 

int minimumElements(vector<int> &num, int Target)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (Target+1,0));
    for(int T = 0; T<= Target; T++){
        if(T % num[0] == 0)
            dp[0][T] = T/num[0];
        else
            dp[0][T] = 1e9;
    }

    for(int ind=1; ind<n;ind++){
        for(int T = 0; T<= Target; T++){
            int notTake = 0 + dp[ind-1][T];
            int Take = INT_MAX;
            if (num[ind] <= T) {
              Take = 1 + dp[ind][T - num[ind]];
            }
            dp[ind][T] = min(notTake,Take);
        }
    }
    int ans = dp[n-1][Target];
    if(ans >= 1e9) return -1;
    else return ans;
}

//Space optimisation
#include <bits/stdc++.h> 

int minimumElements(vector<int> &num, int Target)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(Target+1,0), curr(Target+1,0);
    for(int T = 0; T<= Target; T++){
        if(T % num[0] == 0)
            prev[T] = T/num[0];
        else
            prev[T] = 1e9;
    }

    for(int ind=1; ind<n;ind++){
        for(int T = 0; T<= Target; T++){
            int notTake = 0 + prev[T];
            int Take = INT_MAX;
            if (num[ind] <= T) {
              Take = 1 + curr[T - num[ind]];
            }
            curr[T] = min(notTake,Take);
        }
        prev = curr;
    }
    int ans = prev[Target];
    if(ans >= 1e9) return -1;
    else return ans;
}