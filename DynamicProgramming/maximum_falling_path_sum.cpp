#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>> &matrix){
    if(j<0 || j>=matrix[0].size()) return -1e9;
    if(i == 0) return matrix[0][j];

    int up = matrix[i][j] + f(i-1, j,matrix);
    int d_left = matrix[i][j] + f(i-1,j-1,matrix);
    int d_right = matrix[i][j] + f(i-1,j+1,matrix);

    return max(up, max(d_left,d_right));
}

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    for(int j=0;j<m;j++){
        maxi = max(maxi, f(n-1, j, matrix));
    }
}

/******************************* Memoization Approach  ***********************************/

/*
#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

    // Boundary conditions
    if (j < 0 || j >= matrix[0].size()) return -1e9;
    if (i == 0) return matrix[0][j];
    if (dp[i][j] != -1) return dp[i][j];

    int s = matrix[i][j] + f(i - 1, j, matrix, dp);
    int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

    dp[i][j] = max(s, max(ld, rd));
    return dp[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxPathSum = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxPathSum = max(maxPathSum, f(n - 1, j, matrix, dp));
    }

    return maxPathSum;
}
*/

/******************  Tabulation Approach  ****************/

/*
#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j=0; j<m; j++) dp[0][j] = matrix[0][j];
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m;j++){
                    int s = matrix[i][j] + dp[i-1][j];
                    int ld = matrix[i][j];
                    if( j-1 >= 0) ld += dp[i-1][j-1];
                    else ld += -1e9; 
                    int rd = matrix[i][j];
                    if (j + 1 < m){
                      rd += dp[i - 1][j + 1];
                    }else{
                        rd += -1e9;
                    }
                      dp[i][j] = max(s, max(ld, rd));
            }
        }
        int maxi = -1e9;
        for(int j=0;j<m;j++){
            maxi = max(maxi, dp[n-1][j]);
        }
            return maxi;
}
*/

/********************** Space Optimisation *****************************/

/*
#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m,0), curr(m,0);

    for(int j=0; j<m; j++) prev[j] = matrix[0][j];
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m;j++){
                    int s = matrix[i][j] + prev[j];
                    int ld = matrix[i][j];
                    if( j-1 >= 0) ld += prev[j-1];
                    else ld += -1e9; 
                    int rd = matrix[i][j];
                    if (j + 1 < m){
                      rd += prev[j + 1];
                    }else{
                        rd += -1e9;
                    }
                      curr[j] = max(s, max(ld, rd));
            }
            prev = curr;
        }
        int maxi = -1e9;
        for(int j=0;j<m;j++){
            maxi = max(maxi, prev[j]);
        }
            return maxi;
}


*/