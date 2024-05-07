#include<iostream>
#include<vector>
using namespace std;

void subset(vector<int> &set , vector<vector<int>> &ans , vector<int> &sol , int i , int sum , int target)
{
    if(sum == target)
    {
    ans.push_back(sol);
    return ;
    }
    
    if(i >= set.size())
    return ;
    
    if(sum  + set[i] <= target)
    {
        //exclude
        
        subset(set , ans , sol, i+1 , sum , target );
        
        //include
        
        sol.push_back(set[i]);
        subset(set , ans , sol, i+1 , sum+set[i] , target );
        sol.pop_back();
        
    }
}

int main ()
{
   vector<int> set = {7 ,11  ,13 , 24};
    vector<vector<int>> ans;
    vector<int> sol;
    int sum = 0;
    int t = 31;
    subset(set , ans , sol ,0  , sum , t);
    
    for(auto i : ans)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}