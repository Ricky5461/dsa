// total space complexity of adjancy list is O(n+2m) n for node and 2m for total degree of node
 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    vector<int>adj[n+1];      
    /** when we do arr[1].push_back(2)
                    arr[1].push_back(3)
                    arr[1].push_back(5) it dynamically moving the index and increasing the array size
     */

  vector<vector<int>>arr(n+1) 
    // for better uderstanding  we take vector of vector of n+1 node where 
    //  every node will have their own vector of adjancy node
      
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<" : ";
        for(int k:adj[i]){
            cout<<k<<" ";
        }
        cout<<"\n";
    }

return 0;
}