#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<pair<int,int>>p={{2,100},{3,200},{4,400}};
    // vector<vector<pair<int,int>>>p();
    // cout<<p[0].first<<"->"<<p[0].second;
    // cout<<"\n"<<p[1].first<<"->"<<p[1].second;

    int n=5;int m=6;
       vector<vector<pair<int,int>>>p(n+1);
    for(int i=1;i<=n;i++){
        cout<<"Enter the number of node connected to \n";
        cout<<"\nNode "<<i<<":";
        int o;
        cin>>o;
        while(o){ 
            cout<<"enter the node and weight\n";
            int u,v;
            cin>>u>>v;
            p[i].push_back({u,v});o--;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<" is connected to \n";
        for(auto p2:p[i]){
            cout<<p2.first<<" Weight:"<<p2.second<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}