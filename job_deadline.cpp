#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> arr1,pair<int,int> arr2){
    return arr1.first>arr2.first;
}
void deadline(vector<pair<int,int>> &arr){
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    for(int i=0;i<arr.size();i++){
        // cout<<arr[i].first<<"  "<<arr[i].second;
        // cout<<endl;
    }
    int ans[3]={0};
    for(int i=0;i<arr.size();i++){
        for(int j=arr[i].second-1;j>=0;j--){
            if (ans[j]==0){
                ans[j]=arr[i].first;
                break;
            }
        }
    }

    for(int i=0;i<=2;i++){
        cout<<ans[i];
        cout<<endl;
    }
}
int main(){
    vector<pair<int,int>> arr;
    arr={{10,2},{20,1},{25,2},{50,1},{40,3},{30,3}};
    deadline(arr);
}