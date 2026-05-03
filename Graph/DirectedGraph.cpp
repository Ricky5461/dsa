// Directed Graph
#include<iostream>
#include<vector>
using namespace std;
int main(){

    cout<<"Enter the number of Node:";
    int n;
    cin>>n;
    cout<<"Enter the number of edge :";
    int m;
    cin>>m;
vector<vector<int>>arr(n+1);
    for( int i=1;i<=n;i++){
        int u,v;
        cout<<" Enter the Node\n";
        cin>>u;
        cout<<"Enter how many number of connected node to it:\n";
        cin>>v;
        while(v){
            int w;
            cout<<"Enter the node to connect ";
            cin>>w;
            arr[u].push_back(w);v--;
        }    
    }
    for(int i=1;i<=n;i++){
        cout<< i<< " is connected to -->{";
            for(int l:arr[i]){
                cout<<l<<" ";
            }
            cout<<"}\n";
        }
    return 0;
}