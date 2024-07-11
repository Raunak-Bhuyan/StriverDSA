long f(int ind, int buy, vector<int> &values, int n, int fee){
    if(ind == n) return 0;

    long profit = 0;
    if(buy){
        profit = max(-values[ind] + f(ind+1, 0, values, n, fee),
                     0 + f(ind+1, 1, values, n, fee));
    }else{
        profit = max(values[ind] - fee + f(ind+1, 1, values, n, fee), 
                     0 + f(ind+1, 0, values, n, fee));
    }
    return profit;
}

int maximumProfit(vector<int> &values, int n, int fee)
{
	// Write your code here.
	return f(0,1, values, n, fee);
}

//space optimisation
int maximumProfit(vector<int> &values, int n, int fee)
{
	// Write your code here.
        long profit = 0;
    long aheadNotBuy = 0, aheadBuy = 0;
    long currBuy, currNotBuy;
    vector<vector<long>> dp(n+1, vector<long> (2, 0));
    aheadNotBuy = aheadBuy = 0;
        for(int ind = n-1; ind>=0; ind--){

            currBuy = max(-values[ind] + aheadNotBuy,
                     0 + aheadBuy);
                
            currNotBuy = max(values[ind] - fee + aheadBuy, 
                     0 + aheadNotBuy);
                               
            
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
}

