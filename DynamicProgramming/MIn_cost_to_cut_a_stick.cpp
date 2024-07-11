#include<bits/stdc++.h>

int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT16_MAX;
    for (int index = i; index <= j; index++)
    {
        int cost = cuts[j+1] - cuts[i-1] + f(i,index-1,cuts,dp) + f(index+1,j,cuts,dp); //left one + right one
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
     
}

int cost(int n, int c, vector<int> &cuts){
    //c: cuts of size c
    //n: length of the stick
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end()); //for making two independent sub-problems we have to sort it.
    vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
    return f(1,c,cuts, dp);
}

//Tabulation
#include<bits/stdc++.h>

int cost(int n, int c, vector<int> &cuts){
    //c: cuts of size c
    //n: length of the stick
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end()); //for making two independent sub-problems we have to sort it.
    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){
            if(i>j) continue;
                int mini = INT_MAX;
                for (int index = i; index <= j; index++)
                {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][index-1] + dp[index+1][j]; //left one + right one
                    mini = min(mini,cost);
                }
                 dp[i][j] = mini;
        }
    }
    return dp[1][c];
}