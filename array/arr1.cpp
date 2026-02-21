#include<iostream>
#include<vector>
using namespace std;
 int main(){
    cout<< "ricky kumar";
    vector<int>arr={3,4,5,1,2,3};
    int n= arr.size();
    int k=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>arr[(i+1)%n])k++;
    }
    if(k<=1)cout<< true;
    else cout<< false;
    return 0;
 }