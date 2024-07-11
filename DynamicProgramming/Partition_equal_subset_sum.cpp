bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: We can always make a sum of 0 by not picking any elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: With only the first element, we can only form the subset sum if it equals arr[0]
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target) {
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take | notTake;
        }
    }

    return dp[n - 1][k];
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int total_sum = 0;
	for(int i=0;i<n;i++){
		total_sum += arr[i];
	}

	if(total_sum%2 != 0) return false;
	int target = total_sum/2;

	return subsetSumToK(n,target,arr);
}