#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int in;
    vector<int> tree;
    while(cin >> in){
        tree.push_back(in);
    }
    size_t l=0,r=0;
    while (r<tree.size()){
        // 镜像当前层
        for (size_t i=l;i<=(r+l)/2;i++){
            swap(tree[i],tree[r+l-i]);
        }
        // 更新l,r
        l = 2 * l + 1;
        r = 2 * r + 2;
    }
    for (size_t i=0;i<tree.size();i++){
        cout << tree[i] << " ";
    }
}