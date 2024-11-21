#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct Graph{
    int N;
    int** G;
    Graph(int n):N(n){
        G=new int*[N];
        for(int i=0;i<N;i++){
            G[i]=new int[N];
            for(int j=0;j<N;j++){
                G[i][j]=0;
            }
        }
    }
    void addEdge(int u,int v){
        G[u][v]=1;
    }
    int indegree(int v){
        int count=0;
        for(int i=0;i<N;i++){
            if(G[i][v]==1){
                count++;
            }
        }
        return count;
    }

};

int main() {
    int T,N,C;
    cin>>T;
    while(T--){
        cin>>N>>C;
        Graph g(N);
        for(int i=0;i<C;i++){
            int u,v;
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }
        int ret = 0;
        for(int i=0;i<N;i++){
            ret = max(ret, g.indegree(i));
        }
        cout<<ret<<endl;
    }
}