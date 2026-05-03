#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


// log(n) time to divide and n time to merge
// as  1 divide=2 two arr
// 2 divide =4 two arr
// 3 divide =8 two arr
// k divide = 2^k two arr element
// k is defined as n=2^k => k= log(n)
// hence log(n) time to divide

// total division = log(n)
// merging each level takes n time

void merge(vector<int>&arr,int low,int mid,int high){

    int left=low; int right=mid+1;
    vector<int>temp={};int k=0;

    while(left<= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else {
            temp.push_back(arr[right++]);
        }
    }

    while(left<=mid){
        temp.push_back(arr[left++]);
    }

    while(right<=high){
        temp.push_back(arr[right++]);
    }

    // for(int i=0;i<temp.size();i++){
    //     arr[low++]=temp[i];
    // }
   
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

}

void merge_sort(vector<int>&arr,int low,int high ){
    if(low>=high) return;
    int mid= (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){

    vector<int>arr={23,434,545,54,2,0,-34,3,1,-2};

    for(int n:arr)cout<< n<<"\t"<<endl;
    int n=arr.size();
    int low=0;int high=n-1;
    merge_sort(arr,low,high);
    cout<<"After Merge Sort"<<endl;
    for(int n:arr)cout<< n<<"\t"<<endl;
    return 0;
}