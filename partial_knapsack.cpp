#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int>& item1, pair<int, int>& item2) {
    return ((double)(item1.first) / item1.second) > ((item2.first) / item2.second);
}
void partialKnapsack(vector<pair<int, int>>& items , int W) {
    sort(items.begin(), items.end(), cmp);
    double profit = 0;
    int weight = 0;
    for(int i =0 ; i<items.size(); i++)
    {
        if(weight < W)
        {
            int a = min(items[i].second , W-weight);
            profit += (items[i].first * a)/items[i].second;
            weight += a;
        }
    }
    cout<<profit;
}

int main() {
    vector<pair<int, int>> items =  {{100, 20}, {60, 10}, {120,30}};  
    int capacity = 50;
    partialKnapsack(items , 50);
    return 0;
}
