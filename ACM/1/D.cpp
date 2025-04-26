#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<array>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> d(n);
    for (int i=0 ;i<n ;i++)
        cin>>d[i].first>>d[i].second;
    sort(d.begin(),d.end(),
    [](pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
        }
    );

    int count = 1, l=d[0].first,r=d[0].second;
    for (int i=1 ;i<n ;i++){
        if(r<d[i].first){
            count++;
            l=d[i].first;
        }
        r=max(d[i].second,r);
    }
    cout<<count;
    return 0;
}