#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    long long sum=0,maxsum=LONG_MIN;
    int startpos=0,tempstart=0,endpos=0;
    for(int i=0;i<arr.size();i++){
        if(sum==0){
            tempstart=i;
        }
        sum+=arr[i];
        if(sum>maxsum){
            maxsum=sum;
            startpos=tempstart;
            endpos=i;
        } 
        if(sum<0){
            sum=0;
         }
    }
    cout<<"Maxsum="<<maxsum;
    cout<<"\n";
    for(int i=startpos;i<=endpos;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}