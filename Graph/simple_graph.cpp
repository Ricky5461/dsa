// This is a simple graph representation using adjacency matrix
// space complexity of adjacency matrix is O(n^2) where n is number of node in
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"enter the number of node:"<<endl;
    cin>>n;
    cout<<"\nenter the number of edge:";
    cin>>m;
     int adj[6][6]={0};
    //  vector<vector<int>> adjacacnyMAtrix(n+1,vector<int>(n+1,0));//  n X n  : matrix

    // Adjacancy matrix Adj[n+1][m+1]
    for(int i=0;i<m;i++){
       int u,v;
       cout<<"enter the first node and second node:";
       cin>>u>>v;
       adj[u][v]=1;
       adj[v][u]=1;
    }
    for(int i=0;i<=n;i++){
        for(int k=0;k<=n;k++){
            cout<<adj[i][k]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}