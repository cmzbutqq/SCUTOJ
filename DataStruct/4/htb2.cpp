#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    size_t L;
    int K;
    cin >> L;
    int* ht = new int[L];

    for (size_t i = 0; i < L; i++) {
        ht[i] = -1;
    }
    
    string s;
    getline(cin, s);
    getline(cin, s);
    stringstream ss(s);
    while(ss >> K){
        size_t idx = K % L;
        while(ht[idx] != -1){
            idx = (idx + 1) % L;
        }
        ht[idx] = K;
    }
    for (size_t i = 0; i < L; i++) {
        if (ht[i] == -1)
            continue;
        cout << i << ' ' << ht[i] << endl;
    }
}