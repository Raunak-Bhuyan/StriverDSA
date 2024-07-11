int findNumberOfLIS(vector<int> &arr) {
  // Write your code here.
  int n = arr.size(); 
  vector<int> dp(n, 1), count(n,1);
    int maxi = 1;
  for (int i = 0; i < n; i++){
      for(int prev = 0; prev < i; prev++){
          if(arr[i] > arr[prev] && 1 + dp[prev] > dp[i]){
              dp[i] = 1 + dp[prev];
              count[i] = count[prev]; //inherit
          }
          else if(arr[prev] < arr[i] && 1+dp[prev] == dp[i]){
              count[i] += count[prev]; //increase the count
          }
      }

    maxi = max(maxi,dp[i]);
  }
  int number = 0;
  for(int i=0; i<n; i++){
      if(dp[i] == maxi){
          number += count[i];
      }
  }
    return number;
}