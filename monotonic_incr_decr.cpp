#include<iostream>
#include<vector>
using namespace std;
bool isMonotonic(vector<int>&arr){
    bool increase=true;
    bool decrease=true;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1])decrease=false;
        else if(arr[i]<arr[i-1])increase=false;
    }
    return increase||decrease;
}
int main(){
    vector<int>arr={1,2,2,3,1};
    vector<int>arr2={6,5,4,4,3};
    if(isMonotonic(arr2))cout<<"true";
    else cout<<"false";
    return 0;
}
