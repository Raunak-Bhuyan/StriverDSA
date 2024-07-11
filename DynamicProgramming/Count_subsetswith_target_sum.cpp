int f(int ind, int Target, vector<int> &arr){
	if(Target == 0) return 1;
	if(ind == 0) return (arr[ind] == Target);

	int not_pick = f(ind-1,Target,arr);
	int pick = 0;
	if(arr[ind] <= Target)
		pick = f(ind-1,Target-arr[ind],arr);

	return not_pick + pick ; 
}

int findWays(vector<int>& arr, int k)
{	
	int n=arr.size();
	// Write your code here.
	return f(n-1,k, arr);
}


int f(int ind, int Target, vector<int> &arr, vector<vector<int>> &dp){
	if(Target == 0) return 1;
	if(ind == 0) {
		if(Target == 0 && arr[0] == 0) return 2;
		if(Target == 0 || Target == arr[0]) return 1;
		else return 0;
	}
	if(dp[ind][Target] != -1) return dp[ind][Target];
	
	int not_pick = f(ind-1,Target,arr,dp);
	int pick = 0;
	if(arr[ind] <= Target)
		pick = f(ind-1,Target-arr[ind],arr,dp);

	return dp[ind][Target] = not_pick + pick ; 
}

int findWays(vector<int>& arr, int k)
{	
	int n=arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1,-1));
	// Write your code here.
	return f(n-1,k, arr,dp);
}


int findWays(vector<int> &num, int tar){
    int n = num.size();
    vector<int> prev(tar+1, 0), curr(tar+1, 0);
    prev[0] = curr[0] = 1;
    if(num[0] <= tar) prev[num[0]] = 1;
    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum<= tar; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(num[ind] <= sum) take = prev[sum - num[ind]];
            
            curr[sum] = notTake + take;
        }
        prev = curr;
    }
    return prev[tar];
}
