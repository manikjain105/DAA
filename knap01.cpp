#include<iostream>
#include<vector>
using namespace std;
int n = 3;
int W = 50;
vector<vector<int> > dp(n+1 , vector<int>( W+1) );
int knap(int w[] , int val[] , int n , int W)
{
    // vector<vector<int> > dp(n+1 , vector<int>( W+1) );
    for(int i = 0; i<= n; i++)
    {
       for(int j = 0; j<= W; j++)
       {
           if( i ==0 || j== 0)
           {
               dp[i][j] = 0;
           }
           else if (w[i-1] <= j)
           {
               dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j-w[i-1]]);
           }
           else
           dp[i][j] = dp[i-1][j];
       }
    }
    return dp[n][W];
}

int main ()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    // int W = 50;
    vector<int> v;
    int m = 0;
    int max_pf = knap(weight , profit , 3 ,  W);
    cout << max_pf<<endl;
    int k = W;
    int i = 3;
    while(i > 0)
    {
        if(dp[i][k] != dp[i-1][k])
        {
            // store[m++] = i-1;
            v.push_back(i-1);
            k = k- weight[i-1];
        }
        else
        i = i-1;
    }
    for (auto l : v)
    {
        cout<<l<<" ";
        // cout<<store.size();
    }
}