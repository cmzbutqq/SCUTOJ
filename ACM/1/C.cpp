#include <iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
    int n,m=1;
    cin>>n;
    int a[n],b[n];
    for(int i = 0; i<n ; i++)
        cin >> a[i];

    b[0]=a[0];
    for(int i = 1; i<n ; i++){
        if(a[i]!=a[i-1])
            b[m++]=a[i];
    }
    cout<<m<<'\n'<<b[0];
    for(int i = 1; i<m ; i++)
        cout<<' '<<b[i];
    return 0;
}