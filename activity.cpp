#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
bool cmp (pair<int , int>a , pair<int , int>b)
{
    return a.second < b.second;
}

void activity(vector<pair<int , int>> &v)
{
    sort (v.begin() , v.end() , cmp);
    for(auto i : v)
    {
    // cout<<i.first<<"  "<<i.second;
    cout<<endl;
    }
    int a = 1;
    int et = v[0].second;
    for(int i = 1; i<v.size(); i++)
    {
        if(v[i].first >= et)
        {
         a++;
         et = v[i].second;  
        }
    }
    cout<<a;
}
int main()
{
    vector<pair<int , int>> v ={{0,6},{5,7},{8,9},{5,9},{1,2},{3,4}};
    activity(v);
}