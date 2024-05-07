#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int findfreq(int freq[], int i, int j);
int find_obst(int key[], int freq[], int n);

int find_obst(int key[], int freq[], int n)
{
    // vector<vector<int>> dp(n, vector<int>(n));
    int dp[n][n];
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = freq[i];
    }
    
    for(int l = 2; l <= n; l++)
    {
        for (int i = 0; i <= n - l+1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            int sum_freq = findfreq(freq, i, j);
            for(int k = i; k <= j; k++)
            {
                int cost = (k == i)? 0 : dp[i][k-1];
                cost += (k == j)? 0 : dp[k+1][j];
                cost += sum_freq;
                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[0][n-1];
}

int findfreq(int freq[], int i, int j)
{
    int sum = 0;
    for(int k = i; k <= j; k++)
        sum += freq[k];
    return sum;
}

int main ()
{
    int keys[] = {10, 12, 20}; 
    int freq[] = {34, 8, 50}; 
    int ans = find_obst(keys, freq, 3);
    cout << "Minimum cost is " << ans << endl;
    return 0;
}