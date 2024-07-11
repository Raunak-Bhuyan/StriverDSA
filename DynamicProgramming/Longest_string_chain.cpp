bool check(string &s1, string &s2){
    if(s1.size() != s2.size() + 1) return false;
    int first = 0, second = 0; //two pointers
    while(first < s1.size()){
        if(s1[first] == s2[second]){
            first++; second++;
        }else {
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr){
    // Write your code here.
    int n=arr.size();
    vector<int> dp(n,1);
    int maxi = 1;
    sort(arr.begin(), arr.end(), comp);
    for(int i=0; i<n; i++){
        for(int prev = 0; prev < i; prev++){
            if(check(arr[i],arr[prev]) && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];

            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
        }
    }
    return maxi;
}