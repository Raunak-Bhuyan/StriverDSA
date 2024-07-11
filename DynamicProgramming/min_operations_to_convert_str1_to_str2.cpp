int lcs(string s, string t)
{
	//Write your code here
	int n = s.size(); 
	int m = t.size();
	vector<int> prev(m+1, 0), curr(m+1, 0);

		for(int j = 0; j<=m; j++) prev[j] = 0;


		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
					if(s[i-1] == t[j-1]) curr[j] = 1 + prev[j-1];
					else curr[j] = 0 + max(prev[j], curr[j-1]);
			}
			prev = curr;
		}
	return prev[m];
}

int canYouMake(string &s1, string &s2){
    // Write your code here.
    return s1.size() + s2.size() - 2*lcs(s1,s2);
}