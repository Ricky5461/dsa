#include<iostream>
using namespace std;
int main(){
    int m=4;int n=3;
    // without using any extra array merge this two sorted array in one sorted array
    int nums1[m+n]={0,1,2,10,0,0,0};int nums2[n]={3,4,5};
    int i = m-1;int j=n-1;int k=m+n-1;

    while(i >= 0 && j >= 0){
        if(nums1[i]>=nums2[j])nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    /*** if nums1 array element got completed mean all are shifted backward and need to forward the nums2 element ***/
    while(j>=0)nums1[k--]=nums2[j--];
    
    for(int o:nums1)cout<<o<<"\t";

    return 0 ;
}