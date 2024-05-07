#include<iostream>
#include<vector>
using namespace std;
bool safe(vector<int> &x , int i , int k)
{
    for(int j = 1; j<k; j++)
    {
        if (x[j] == i || abs(x[j]-i) == abs(j-k))
        return false;
    }
    return true;
}
 void solve_nq(int k ,vector<int> &x,  int n)
 {
     for(int i = 1; i<=n; i++)
     {
         if(safe(x , i , k))
         {
             x[k] = i;
             if(k == n)
             {
                 for(int j =1; j<=n ; j++)
                 cout<<x[j];
                 cout<<endl;
             }
         
         else
         solve_nq( k+1 ,x , n);
         }
     }
 }


int main()
{
    vector<int> x(5,0);
    solve_nq(1, x , 4);
}