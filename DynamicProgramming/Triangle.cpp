#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, int n, vector<vector<int>> &triangle) {
    if (i == n-1) return triangle[i][j];

    int d = triangle[i][j] + f(i+1, j, n, triangle);
    int dg = triangle[i][j] + f(i+1, j+1, n, triangle);

    return min(d, dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    return f(0, 0, n, triangle);
}

/****************  Memoization  ***************/

/*
#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, int n, vector<vector<int>> &triangle,vector<vector<int>> &dp) {
    if (i == n-1) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    
    int d = triangle[i][j] + f(i+1, j, n, triangle, dp);
    int dg = triangle[i][j] + f(i+1, j+1, n, triangle, dp);

    return dp[i][j] = min(d, dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int> (n,-1));
    return f(0, 0, n, triangle, dp);
}

*/

/***************** Tabulation ******************/

/*
int minimumPathSum(vector<vector<int>> &triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int j=0; j<n; j++) 
        dp[n-1][j] = triangle[n-1][j];

    for(int i = n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dg);
        }
    }
    return dp[0][0];
}
*/

/*********************** Space optimisation**************************/

/*
#include <bits/stdc++.h> 
using namespace std;

int minimumPathSum(vector<vector<int>> &triangle, int n) {
    vector<int> front(n,0), curr(n,0);
    for(int j=0; j<n; j++) 
        front[j] = triangle[n-1][j];

    for(int i = n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j+1];
                curr[j] = min(d,dg);
        }
        front = curr;
    }
    return front[0];
}
*/