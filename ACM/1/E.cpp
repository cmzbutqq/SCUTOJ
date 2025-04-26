#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    cin.tie (0);
    ios::sync_with_stdio (false);
    int n,q,k;
    cin>>n;
    int a;
    map<int,int> hash;
    for (int i=0 ;i<n ;i++){
        cin>>a;
        hash[a]++;
    }
    cin>>q;
    for (int i=0 ;i<q ;i++){
        cin>>k;
        cout<<hash[k]<<'\n';
    }
    return 0;
}