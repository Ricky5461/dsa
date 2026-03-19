#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>arr={{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>>arr2[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==0){
               arr2[i][]=0;arr2[][j]=0;
            }
        }
    }
        return 0;
}