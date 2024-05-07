#include<iostream>
using namespace std;
#include<vector>

int findlen(string s1 , string s2 ,int m ,int n)
{
    vector<vector<int>> dp(m+1 ,vector<int>(n+1));
    for(int i =0 ; i<=m ; i++)
    {
        for(int j = 0 ; j<=n ; j++)
        {
            if(i ==0 || j ==0 )
            {
                dp[i][j] = 0;
            }
                else if(s1[i] == s2[j])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j]  , dp[i][j-1]);
            
        }
    }
    return dp[m][n];
}

int main ()
{
     string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();
    int ans = findlen(s1 , s2 ,m , n);
    cout<<ans;
}