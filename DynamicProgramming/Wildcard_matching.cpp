bool f(int i, int j, string &pattern, string &text){
   if(i<0 && j<0)  return true;
   if(i<0 && j>=0) return false;
   if(j<0 && i>=0){
      for(int ind=0; ind<=i; ind++){
         if(pattern[ind] != '*') return false;
      }
      return true;
   }
   if(pattern[i] == text[j] || pattern[i] == '?') return f(i-1,j-1, pattern, text);
   if(pattern[i] == '*') return f(i-1,j,pattern,text)|f(i,j-1,pattern,text);
   else return false;
}

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n=pattern.size();
   int m=text.size();
   return f(n-1,m-1,pattern,text);
}

//Memoization
#include<vector>

bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
   if(i<0 && j<0)  return true;
   if(i<0 && j>=0) return false;
   if(j<0 && i>=0){
      for(int ind=0; ind<=i; ind++){
         if(pattern[ind] != '*') return false;
      }
      return true;
   }
   if(dp[i][j] != -1) return dp[i][j];

   if(pattern[i] == text[j] || pattern[i] == '?') return dp[i][j] = f(i-1,j-1, pattern, text, dp);
   if(pattern[i] == '*') return dp[i][j] = f(i-1,j,pattern,text, dp)|f(i,j-1,pattern,text, dp);
   else return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{ 
   // Write your code here.
   int n=pattern.size();
   int m=text.size();
   vector<vector<int>> dp(n, vector<int> (m,-1));
   return f(n-1,m-1,pattern,text,dp);
}

//Tabulation
#include<vector>

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n=pattern.size();
   int m=text.size();
   vector<vector<bool>> dp(n+1, vector<bool> (m+1,false));
   dp[0][0] = true; //if(i==0 && j==0)  return true;
   for(int j=1; j<=m; j++){
      dp[0][j] = false;
   }

   for(int i=1; i<=n; i++){
      int flag = true;
      for(int ind=1; ind<=i; ind++){
         if (pattern[ind - 1] != '*') {
           flag = false;
           break;
         }
      }
      dp[i][0] = flag;
   }

   for(int i=1;i<=n;i++){
      for(int j=1; j<=m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if(pattern[i-1] == '*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
            else  dp[i][j] = false;
      }
   }
   return dp[n][m];
}

//Space optimisation
#include<vector>

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n=pattern.size();
   int m=text.size();
   vector<bool> prev(m+1, false), curr(m+1, false);
    prev[0] = true; //if(i==0 && j==0)  return true;
   for(int j=1; j<=m; j++){
      prev[j] = false;
   }


   for(int i=1;i<=n;i++){
      //curr is the current row's column
      //and that curr's 0th row has to be assigned everytime
      
      bool flag = true;
      for(int ind=1; ind<=i; ind++){
         if (pattern[ind - 1] != '*') {
           flag = false;
           break;
         }
      }
      //for every row
      //you are asssigning the 0th column's value
      curr[0] = flag;

      for(int j=1; j<=m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') curr[j] = prev[j-1];
            else if(pattern[i-1] == '*') curr[j] = prev[j] | curr[j-1];
            else  curr[j] = false;
      }
      prev = curr;
   }
   return prev[m];
}