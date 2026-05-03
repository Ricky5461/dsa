#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>>arr={{4,7},{1,4}};
    sort(arr.begin(),arr.end());
    for(auto& n:arr){
        for(int num:n)cout<<num<<" ";
    }
    return 0;
}