#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    size_t N;
    cin >> N;
    int in,sum_weight = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (size_t i = 0; i < N; i++){
        cin >> in;
        pq.push(in);
    }

    while (pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        sum_weight += a+b;
    }
    cout << sum_weight << endl;
}