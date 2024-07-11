int f(int ind,int N, vector<int> &price){
	if(ind == 0){
		return N*price[0];
	}

	int not_take = 0 + f(ind-1,N, price);
	int take = -1e9;
	int rodlength = ind+1;
	if(rodlength <= N) take = price[ind] + f(ind,N-rodlength, price);

	return max(not_take, take);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	return f(n-1, n, price);
}


//Memoization
int f(int ind,int N, vector<int> &price, vector<vector<int>> &dp){
	if(ind == 0){
		return N*price[0];
	}
	if(dp[ind][N] != -1) return dp[ind][N];

	int not_take = 0 + f(ind-1,N, price, dp);
	int take = -1e9;
	int rodlength = ind+1;
	if(rodlength <= N) take = price[ind] + f(ind,N-rodlength, price, dp);

	return dp[ind][N] = max(not_take, take);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
	return f(n-1, n, price, dp);
}

//Tabulation
int cutRod(vector<int> &price, int N)
{
	// Write your code here.
	vector<vector<int>> dp(N, vector<int> (N+1, 0));

	for(int n = 0; n<=N; n++){
		dp[0][n] = n*price[0];
	}

	for(int ind=1;ind<N;ind++){
		for(int n = 0; n<=N; n++){
				int not_take = 0 + dp[ind-1][n];
				int take = -1e9;
				int rodlength = ind+1;
				if(rodlength <= n) take = price[ind] + dp[ind][n-rodlength];
				dp[ind][n] = max(not_take,take);
		}
	}
	return dp[N-1][N];
}

//Space Optimisation
int cutRod(vector<int> &price, int N)
{
	// Write your code here.
	vector<int> prev(N+1,0), curr(N+1,0);

	for(int n = 0; n<=N; n++){
		prev[n] = n*price[0];
	}

	for(int ind=1;ind<N;ind++){
		for(int n = 0; n<=N; n++){
				int not_take = 0 + prev[n];
				int take = -1e9;
				int rodlength = ind+1;
				if(rodlength <= n) take = price[ind] + curr[n-rodlength];
				curr[n] = max(not_take,take);
		}
		prev = curr;
	}
	return prev[N];
}
