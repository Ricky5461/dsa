#include<iostream>
#include<vector>
using namespace std;
int main(){

    cout<< "enter the number of node";
    int n;
    cin>>n;
    vector<vector<int>>vec(n+1);
    
    int u,v;
    for(int i=1;i<=n;i++){
    cout<<"Enter the node1 and node 2";
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);    
    }

    for(auto u:vec){
        for (int i:u)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
        
    }
    return 0;
}