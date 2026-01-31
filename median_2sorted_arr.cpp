#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int>arr1={1,2,4,5,6,7};
    vector<int>arr2={5,8,12,13,14,67};
    vector<int>merged;
    int i=0;int j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]) merged.push_back(arr1[i++]);
        else merged.push_back(arr2[j++]);
    }
    while (i<arr1.size()) merged.push_back(arr1[i++]);
    while (j<arr2.size()) merged.push_back(arr2[j++]);
    int n=merged.size();
    if(n%2==0){
        cout<< (merged[n/2-1]+merged[n/2])/2.0;
    }
    else cout<< merged[n/2];
    return 0;
}