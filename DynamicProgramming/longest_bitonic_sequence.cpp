int longestBitonicSubsequence(vector<int>& arr, int n)
{
    vector<int> dp1(n,1);
    for(int i=0; i<n; i++){
        for(int prev = 0; prev < i; prev++){
            if(arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i]){
                dp1[i] = 1 + dp1[prev];

            }
        }
    }

    vector<int> dp2(n,1);
    for(int i=n-1; i>=0; i--){
        for(int prev = n-1; prev > i; prev--){
            if(arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i]){
                dp2[i] = 1 + dp2[prev];

            }
        }
    }
	int maxi = 0;
	for(int i=0; i<n; i++){
        // Only consider it a bitonic sequence if there's both an increasing part and a decreasing part (additional gfg constraint)
        //if(dp1[i] > 1 && dp2[i] > 1) {
           // maxi = max(maxi, dp1[i] + dp2[i] - 1);
        //}
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
	return maxi;
}

