#include<iostream>
using namespace std;
#include<vector>
#include<climits>
int find_op(int p[] , int n )
{
    // vector<vector<int>> dp(n , vector<int> (n));
    int dp[n][n];
    for(int i = 1 ; i<n; i++)
    {
        for(int j = 1 ; j<n; j++)
        {
            if(i == j)
            dp[i][j] = 0;
        }
    }
    
    for(int l = 2; l<n; l++)
    {
        for (int i = 1; i<n-l+1; i++)
        {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k = i ; k<j; k++)
            {
                int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < dp[i][j])
                dp[i][j]= q;
            }
        }
    }
    return dp[1][n-1];
}
int main ()
{
    int  p [] = {1 , 2 , 3  , 4};
    int ans = find_op(p , 4);
    cout<<ans;
}