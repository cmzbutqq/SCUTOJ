#include <iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
    int n,k;
    string s;
    cin>>n>>s>>k;

    int lower[26],upper[26];
    for(int i=0;i<26;++i)
        lower[i]=upper[i]=0;
    for(int i=0;i<n;++i){
        char c = s[i];
        if ('a'<=c&&c<='z')
            lower[c-'a']++;
        else
            upper[c-'A']++;
    }
    int pairs=0;

    for(int i=0;i<26;++i){
        int m = min(lower[i],upper[i]);
        int left = max(lower[i],upper[i])-m;
        pairs+=m;
        if(left && k){
            int able = min(left/2,k);
            pairs+=able;
            k-=able;
        }
    }
    cout<<pairs;
    return 0;
}