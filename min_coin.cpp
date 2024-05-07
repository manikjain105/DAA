#include<iostream>
using namespace std;
#include<vector>
#include<climits>
int find_coin(int coin[] , int amount , int n)
{
    vector<vector<int>> dp(n+1 ,vector<int>(amount+1, INT_MAX-1));
    for(int i = 0; i <=n ;i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<= amount; j++)
        {
         if(coin[i-1] <= j)
         {
             dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j-coin[i-1]]);
         }
         else
         dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][amount];
}

int main()
{
    int coins[] = {9 , 6 ,5 ,1};
    int target = 11;
    int ans = find_coin(coins , target , 4);
    cout <<ans;
}