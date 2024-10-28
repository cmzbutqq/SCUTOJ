#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for(auto it = s.rbegin();it!=s.rend();it++)
            cout<<*it;
        cout<<endl;
    }
}