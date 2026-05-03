#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr={23,34,545,23,3,0,-1};
      int j;
    for(int i=0;i<arr.size();i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]); j--;
        }
    }
    for(int c:arr)cout<< c<<"\t";
}