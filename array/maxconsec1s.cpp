#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr={1,0,1,1,0,1,1,1,0,1};
    int n=(int)arr.size();
    int count=0;int maxCount=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxCount=max(maxCount,count);
        }
        else {
            count=0;
        }
    }
cout<<maxCount<<endl;
    return 0;
}