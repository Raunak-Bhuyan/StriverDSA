int f(int ind, vector<int> &nums, int k){
    if(ind == nums.size()) return 0;
    int len = 0;
    int maxi = INT_MIN; 
    int maxAns= INT_MIN;
    for(int j=ind; j<min(nums.size(), ind+k); j++){
        len++;
        maxi = max(maxi, num[j]);
        int sum = len*maxi + f(j+1);
        maxAns = max(maxAns, sum);
    }
    return maxAns;

}

int maximumSubarray(vector<int> &nums, int k){
    int n = nums.size();
    return f(0,nums,k);
}

//Memoization
int f(int ind, vector<int> &nums, int k, vector<int> &dp){
    if(ind == nums.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
    int len = 0;
    int maxi = INT_MIN; 
    int maxAns= INT_MIN;
    for(int j=ind; j<min(nums.size(), ind+k); j++){
        len++;
        maxi = max(maxi, num[j]);
        int sum = len*maxi + f(j+1, nums, k,dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;

}

int maximumSubarray(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(0,nums,k,dp);
}

//Tabulation

int maximumSubarray(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> dp(n+1, 0);
  
    for(int ind = n-1; ind>=0; ind--){
        int len = 0;
        int maxi = INT_MIN; 
        int maxAns= INT_MIN;
        for(int j=ind; j<min(nums.size(), ind+k); j++){
            len++;
            maxi = max(maxi, num[j]);
            int sum = len*maxi + dp[j+1];
            maxAns = max(maxAns, sum);
    }
    dp[ind] = maxAns;
    }
    return dp[0];
}