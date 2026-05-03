#include<iostream>
using namespace std;
 int main(){
    int  n=99;int ans;
    int low=1;int high=100;int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    cout<<high<<endl;

    return 0;
 }