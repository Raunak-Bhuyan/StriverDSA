int f(int ind, int prev, int arr[],int n){
    if(ind == n) return 0;

    int len = 0 + f(ind+1, prev, arr, n);
    if(prev == -1 || arr[ind] > arr[prev]){
        len = max(len,1 + f(ind+1, ind, arr, n));
    }
    return len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return f(0,-1,arr,n);
}

//Memoization
#include<bits/stdc++.h>

int f(int ind, int prev, int arr[],int n, vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
    int len = 0 + f(ind+1, prev, arr, n, dp);
    if(prev == -1 || arr[ind] > arr[prev]){
        len = max(len,1 + f(ind+1, ind, arr, n, dp));
    }
    return dp[ind][prev+1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return f(0,-1,arr,n,dp);
}

//Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
    // Initialize a 2D DP array
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = ind - 1; prev >= -1; prev--) {
            int len = 0 + dp[ind + 1][prev + 1];
            if (prev == -1 || arr[ind] > arr[prev]) {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev + 1] = len;
        }
    }
    
    // The result is stored in dp[0][0]
    return dp[0][0];
}

//for printing the subsequence
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if(arr[prev] < arr[i] && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        for(auto it: temp) cout << it << " ";
        cout << endl;
        return maxi;
    }
};